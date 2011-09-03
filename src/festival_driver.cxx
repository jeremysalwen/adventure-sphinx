#include "festival_driver.h"
#include <festival.h>
#include <unistd.h>
#include "hdr.h"
#define VOICEDIR PACKAGE_DATA_DIR "/adventure-festvox/"

#define SCRIPTNAME VOICEDIR "festvox/SLP_adventure_jas_ldom.scm"

void initAdventureFestival() {
	festival_initialize(TRUE,1000000);
	festival_eval_command("(set! voice-locations (cons (cons 'SLP_adventure_jas_ldom \"" VOICEDIR "\" voice-locations)))");
	festival_load_file(SCRIPTNAME);
	festival_eval_command("(voice_SLP_adventure_jas_ldom)");
}
extern const char    fiotape[] = "Ax3F'\003tt$8h\315qer*h\017nGKrX\207:!l";
const char   *ftape = fiotape;            /* pointer to encryption tape   */

void festival_speak(const struct text *msg)			/* read, decrypt, and print a message (not
				 * ptext)      */
				 /* msg is a pointer to seek address and length
				 * of mess */
{
	char tmpstr[MAXSTR];
	char* output=tmpstr;
	char   *s, nonfirst;


	s = msg->seekadr;
	nonfirst = 0;
	while (s - msg->seekadr < msg->txtlen) {	/* read a line at a time */
		ftape = fiotape;	/* restart decryption tape      */
		while ((*s++ ^ *ftape++) != TAB);	/* read past loc num       */
		/* assume tape is longer than location number           */
		/* plus the lookahead put together                    */
		if ((*s ^ *ftape) == '>' &&
		    (*(s + 1) ^ *(ftape + 1)) == '$' &&
		    (*(s + 2) ^ *(ftape + 2)) == '<')
			break;
		if (blklin && !nonfirst++)
			*output++ ='\n';
		do {
			if (*ftape == 0)
				ftape = fiotape;	/* rewind decryp tape */
			*output++ =*s ^ *ftape;
		} while ((*s++ ^ *ftape++) != LF);	/* better end with LF   */
	}
	*output=0;
	//printf("Saying %s\n",tmpstr);
	festival_say_text(tmpstr);
}

void festival_pspeak(int m,int skip)			/* read, decrypt an print a ptext message              */
		/* msg is the number of all the p msgs for
				 * this place  */
		/* assumes object 1 doesn't have prop 1, obj 2
				 * no prop 2 &c */
{
	char OUTBUFF[MAXSTR];
	char* OUTPUT=OUTBUFF;
	char   *s, nonfirst;
	char   *numst, save;
	struct text *msg;
	char   *tbuf;

	msg = &ptext[m];
	if ((tbuf = (char *) malloc(msg->txtlen + 1)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	memcpy(tbuf, msg->seekadr, msg->txtlen + 1);	/* Room to null */
	s = tbuf;

	nonfirst = 0;
	while (s - tbuf < msg->txtlen) {	/* read line at a time */
		ftape = fiotape;	/* restart decryption tape      */
		for (numst = s; (*s ^= *ftape++) != TAB; s++);	/* get number  */

		save = *s;	/* Temporarily trash the string (cringe) */
		*s++ = 0;	/* decrypting number within the string          */

		if (atoi(numst) != 100 * skip && skip >= 0) {
			while ((*s++ ^ *ftape++) != LF)	/* flush the line    */
				if (*ftape == 0)
					ftape = fiotape;
			continue;
		}
		if ((*s ^ *ftape) == '>' && (*(s + 1) ^ *(ftape + 1)) == '$' &&
		    (*(s + 2) ^ *(ftape + 2)) == '<')
			break;
		if (blklin && !nonfirst++) {
			if(OUTPUT!=OUTBUFF) {
				*OUTPUT=0;
				festival_say_text(OUTBUFF);
				OUTPUT=OUTBUFF;
			}
		}
		do {
			if (*ftape == 0)
				ftape = fiotape;
			*OUTPUT++=*s ^ *ftape;
		} while ((*s++ ^ *ftape++) != LF);	/* better end with LF   */
		if (skip < 0)
			break;
	}
	free(tbuf);
	*OUTPUT=0;
	festival_say_text(OUTBUFF);
}
void festival_printf(const char *format, ...) {
	va_list args;
	va_start(args, format); /* Initialize the va_list */
	char BUFFER[4096];
	vsnprintf(BUFFER,4096, format, args);
	va_end(args);
	festival_say_text(BUFFER);
}
