/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Jeremy  Salwen 2011 <jeremysalwen@gmail.com>
	 * 
 * adventure-sphinx is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
	 * 
 * adventure-sphinx is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "asr_input.h"
#include <pocketsphinx.h>
float startthreshold=-40;
float endthreshold=-55;

//The following are defined for use of storing the input from the mic
// to be grabbed by the speech recognizer.
#define BUFFERSIZE ((int)16000*10)

//BLOCKSIZE must be less than BUFFERSIZE for it to make sense.
#define BLOCKSIZE 2048

//PRESILENCE+POSTSILENCE+MAXRECORD must be less than BUFFERSIZE (so it won't 
// overflow)
#define PRESILENCE ((int)(16000*1))
#define POSTSILENCE ((int)(16000*1))
#define MAXRECORD ((int)(16000*7))

static float inputbuffer[BUFFERSIZE];
//The start of where to read the input from.
static volatile int inputstart;
//The first index you can't read input from.
static volatile int writeidx;


static volatile unsigned int numsinceblock;
static volatile unsigned int numrecorded;

static volatile float currentdbs;

enum recordingstatus {
	ignore,waiting,recording,postsilence,isdone
};

static volatile enum recordingstatus inputDone;

pthread_mutex_t input_transfer_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  input_transfer_cond   = PTHREAD_COND_INITIALIZER;

static int adventureCallback( const void *in, void *out,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
	if( inputDone==isdone ) {
		pthread_mutex_lock(&input_transfer_mutex);
		pthread_cond_signal (&input_transfer_cond); 
		pthread_mutex_unlock(&input_transfer_mutex);
		return 0;
	}
	if(inputDone==ignore) {
		return 0;
	}
	const float * inflt=(const float*)in;
	unsigned int i;
	for( i=0; i<framesPerBuffer; i++ ) {
		inputbuffer[writeidx++]=*inflt++;
		if(writeidx>BUFFERSIZE) {
			writeidx=0;
		}
		numsinceblock++;
		numrecorded++;
		if(inputDone==postsilence && numrecorded>=POSTSILENCE) {
			inputDone=isdone;
			return 0;
		} else if (inputDone==recording && numrecorded >=MAXRECORD) {
			inputDone=postsilence;
			numrecorded=0;
		} else if(numsinceblock>=BLOCKSIZE) {
			numsinceblock=0;
			//Calculate RMS of block.
			float mean=0;
			float sumsqr=0;
			int n=0;
			//The start of the block we are calculating RMS for.
			int startind=((writeidx-BLOCKSIZE)+BUFFERSIZE)%BUFFERSIZE;
			int j=startind;
			while(j!=writeidx) {
				n++;
				float diff=inputbuffer[j]-mean;
				mean=mean+diff/n;
				sumsqr=sumsqr+diff*(inputbuffer[j]-mean);
				j++;
				if(j==BUFFERSIZE) {
					j=0;
				}
			}
			float RMS=sumsqr/n;
			float db=10*log10(RMS);
			currentdbs=db;
			pthread_mutex_lock(&input_transfer_mutex);
			pthread_cond_signal (&input_transfer_cond); 
			pthread_mutex_unlock(&input_transfer_mutex);
			if(inputDone==waiting) {
				if(db>startthreshold) {
					if(numrecorded<BLOCKSIZE+PRESILENCE) {
						inputstart=0;
					} else {
						//start the buffer from PRESILENCE+BLOCKSIZE samples ago.
						inputstart=(writeidx-(BLOCKSIZE+PRESILENCE)+BUFFERSIZE)%BUFFERSIZE;
					}
					inputDone=recording;
					numrecorded=0;
				}
			} else if(inputDone==recording) {
				if(db<endthreshold) {
					inputDone=postsilence;
					numrecorded=0;
				}
			}
		}
	}
	return 0;
}
static void resetInputBuffer() {
	inputstart=0;
	writeidx=0;
	numsinceblock=0;
	numrecorded=0;
	currentdbs=-90;
	inputDone=ignore;
}

static volatile int lastmeter=0;
void print_dbmeter() {
	putchar('\r');
	int dbint=(int)(currentdbs+80);
	int startthresholdint=(int)(startthreshold+80);
	int endthresholdint=(int)(endthreshold+80);
	int less=dbint;
	if(dbint>endthresholdint) {
		less=endthresholdint;
	}
	for(int i=0; i<less; i++) {
		putchar('=');
	}
	int more=dbint;
	if(dbint>startthresholdint) {
		more=startthresholdint;
	}
	for(int i=endthresholdint; i<more; i++) {
		putchar('+');
	}
	for(int i=startthresholdint; i<dbint; i++) {
		putchar('-');
	}
	for(int i=dbint; i<lastmeter; i++) {
		putchar(' ');
	}
	lastmeter=dbint;
	fflush(stdout);
}
static ps_decoder_t *ps;

void ASR_init(int startThresh, int stopThresh) {
	startthreshold=startThresh;
	endthreshold=stopThresh;
	PaError err;
	err = Pa_Initialize();
	if( err != paNoError ) {
		printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );
	}
	resetInputBuffer();
	PaStream *stream;

	/* Open an audio I/O stream. */
	err = Pa_OpenDefaultStream( &stream,
	                           1,          /* one input channels */
	                           0,          /* no output */
	                           paFloat32,  /* 32 bit floating point output */
	                           16000,
	                           paFramesPerBufferUnspecified, 
	                           adventureCallback, /* this is your callback function */
	                           NULL); /*This is a pointer that will be passed to
	 your callback*/
	if( err != paNoError )  {
		printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );
	}
	err_set_logfp (NULL);
	printf("Initializing ASR engine...\n");

	cmd_ln_t *config;

	config = cmd_ln_init(NULL, ps_args(), TRUE,
						"-ds","2",
						"-topn","2",
						"-maxwpf", "5",
						"-maxhmmpf", "3000",
						"-pl_window","7",
//	                     "-hmm", MODELDIR "/hmm/en_US/hub4wsj_sc_8k",
	                     "-jsgf", GRAMDIR "/yesno.jsgf",
	                     "-dict", MODELDIR "/lm/en_US/cmu07a.dic",
	                     NULL);
	if (config == NULL) {
		exit(1);
	}
	ps = ps_init(config);
	if (ps == NULL) {
		exit(2);
	}
	fsg_set_t* fsgset=ps_get_fsgset(ps);
	jsgf_t* jsgf=jsgf_parse_file (GRAMDIR "/yesno.jsgf",NULL);
	jsgf_rule_iter_t* iter=jsgf_rule_iter (jsgf);
	jsgf_rule_t* rule=NULL;
	while(jsgf_rule_iter_rule(iter)) {
		if(jsgf_rule_public (jsgf_rule_iter_rule(iter))) {
			rule=jsgf_rule_iter_rule(iter);
			break;
		}
		jsgf_rule_iter_next(iter);
	}
	jsgf_rule_iter_free(iter);
	fsg_set_add (fsgset,"yesno",jsgf_build_fsg (jsgf,rule,ps_get_logmath(ps),6.5));
	jsgf_grammar_free (jsgf);
	fsgset=ps_get_fsgset(ps);
	jsgf=jsgf_parse_file (GRAMDIR "/gram.jsgf",NULL);
	iter=jsgf_rule_iter (jsgf);
	rule=NULL;
	while(jsgf_rule_iter_rule(iter)) {
		if(jsgf_rule_public (jsgf_rule_iter_rule(iter))) {
			rule=jsgf_rule_iter_rule(iter);
			break;
		}
		jsgf_rule_iter_next(iter);
	}
	jsgf_rule_iter_free(iter);
	fsg_set_add (fsgset,"gram",jsgf_build_fsg (jsgf,rule,ps_get_logmath(ps),6.5));
	jsgf_grammar_free (jsgf);
	printf("Done initializing ASR engine.\n");
	err = Pa_StartStream( stream );
	if( err != paNoError ) {
		printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );
		exit(7);
	}

}
extern "C" {
	int __BNF_str_io_parser(char* input,char* output,int (*syntax)());
	int command(void);
}

void asr_cleanup() {
	ps_free(ps);
	PaError err = Pa_Terminate();
	if( err != paNoError ) {
		printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );
	}
}

const char* asr_recognize() {
	int rv=ps_start_utt(ps,"newcommand");
	if (rv < 0) {
		fprintf(stderr,"Error starting utterance!\n");
		exit( 1);
	}

	resetInputBuffer();
	inputDone=waiting;
	printf("Recording start...\n");
	fflush(stdout);


	while(inputDone==waiting) {
		pthread_cond_wait(&input_transfer_cond,&input_transfer_mutex);
		print_dbmeter();
	}


	while(inputDone==recording) {
		pthread_cond_wait(&input_transfer_cond,&input_transfer_mutex);
		print_dbmeter();
	}

	while(inputDone==postsilence) {
		pthread_cond_wait(&input_transfer_cond,&input_transfer_mutex);
		print_dbmeter();
	}

	printf("\nDone recording...\n");

	fflush(stdout);
	inputDone=ignore;
	int16 tmpbuff[BUFFERSIZE];
	int count=0;
	if(inputstart<writeidx) {
		for(int i=0; i<writeidx-inputstart; i++) {
			tmpbuff[i]=(int16)(inputbuffer[inputstart+i]*32767);
		}
		count+=writeidx-inputstart;
	} else {
		for(int i=0; i<BUFFERSIZE-inputstart; i++) {
			tmpbuff[i]=(int16)(inputbuffer[inputstart+i]*32767);
		}
		count+=BUFFERSIZE-inputstart;
		for(int i=0; i<writeidx; i++) {
			tmpbuff[i]=(int16)(inputbuffer[i]*32767);
		}
		count+=writeidx;
	}
	rv = ps_process_raw(ps, tmpbuff, count, FALSE, FALSE);
	if(rv<0) {
		fprintf(stderr,"Error processing raw!\n");
		exit(1);
	}
	rv = ps_end_utt(ps);
	if(rv<0) {
		fprintf(stderr,"Error ending utterance!\n");
		exit(2);
	}
	int32 score;
	char const* uttid;
	char const* hyp = ps_get_hyp(ps, &score, &uttid);
	printf("Hypothesis: %s\n",hyp);
	if (hyp == NULL) {
		fprintf(stderr,"Could not get hypothesis. Returning \"f\" instead.\n");
		return "f";
	}
	return hyp;
}
#define HUGESTR 2048

const char* copyword(const char* src, char *dest) {
	while(*src==' ' || *src=='\n' || *src=='\t' || *src=='\r') src++;
	while(!(*src==' ' || *src=='\n' || *src=='\t' || *src=='\r' || *src==0)) *dest++=*src++;
	*dest=0;
	return src;
}

void asr_getin(char ** wrd1, char **wrd2) {
	const char* hyp=asr_recognize();
	static char inbuffer[HUGESTR];
	strcpy(inbuffer,hyp);
	static char outbuffer[HUGESTR] ;
	memset(outbuffer,0,HUGESTR);
	if(strlen(hyp)>HUGESTR) {
		fprintf(stderr,"Input speech too long!\n");
		strcpy(outbuffer,hyp);
		*wrd1=outbuffer;
		*wrd2=outbuffer+strlen(outbuffer);
	}
	if(__BNF_str_io_parser(inbuffer,outbuffer,command)) {
		strcpy(outbuffer,hyp);
	}
	printf("Parsed input: %s\n",outbuffer);
	static char wrd1buff[512];
	static char wrd2buff[512];
	const char* nextword=copyword(outbuffer,wrd1buff);
	copyword(nextword,wrd2buff);
	*wrd1=wrd1buff;
	*wrd2=wrd2buff;
	printf("word1:'%s' word2:'%s'\n",*wrd1,*wrd2);
}


int asr_yes(int x, int y, int z) {
	fsg_set_t* fsgset=ps_get_fsgset(ps);
	fsg_set_select(fsgset,"yesno");
	ps_update_fsgset(ps);
	int     result = TRUE;	/* pacify gcc */
	int    ch;
	for (;;) {
		rspeak(x);	/* tell him what we want */
		const char* input=asr_recognize();
		if(!input) {
			festival_printf("Please answer the question.\n");
			continue;
		}
		ch=*input;
		if (ch  == 'y')
			result = TRUE;
		else if (ch == 'n')
			result = FALSE;
		else if (ch == EOF) {
			festival_printf("user closed input stream, quitting...\n");
			exit(0);
		}
		if (ch == 'y' || ch == 'n')
			break;
		festival_printf("Please answer the question.\n");
	}
	if (result == TRUE)
		rspeak(y);
	if (result == FALSE)
		rspeak(z);
	fsg_set_select(fsgset,"gram");
	ps_update_fsgset(ps);
	return (result);
}


int
asr_yesm(int x, int y, int z)			/* confirm with mspeak          */
{
	fsg_set_t* fsgset=ps_get_fsgset(ps);
	fsg_set_select(fsgset,"yesno");
	ps_update_fsgset(ps);
	int     result = TRUE;	/* pacify gcc */
	int    ch;
	for (;;) {
		mspeak(x);	/* tell him what we want */
		const char* input=asr_recognize();
		if(!input) {
			festival_printf("Please answer the question.\n");
			continue;
		}
		ch=*input;
		if (ch == 'y')
			result = TRUE;
		else if (ch == 'n')
			result = FALSE;
		else if (ch == EOF) {
			festival_printf("user closed input stream, quitting...\n");
			exit(0);
		}
		if (ch == 'y' || ch == 'n')
			break;
		festival_printf("Please answer the question.\n");
	}
	if (result == TRUE)
		mspeak(y);
	if (result == FALSE)
		mspeak(z);
	fsg_set_select(fsgset,"gram");
	ps_update_fsgset(ps);
	return (result);
}
