/*	$NetBSD: io.c,v 1.15 2003/09/19 10:01:53 itojun Exp $	*/

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * The game adventure was originally written in Fortran by Will Crowther
 * and Don Woods.  It was later translated to C and enhanced by Jim
 * Gillogly.  This code is derived from software contributed to Berkeley
 * by Jim Gillogly at The Rand Corporation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)io.c	8.1 (Berkeley) 5/31/93";

__RCSID("$NetBSD: io.c,v 1.15 2003/09/19 10:01:53 itojun Exp $");
#endif
#endif /* not lint */

/*      Re-coding of advent in C: file i/o and user i/o                 */


#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>

#include <arpa/inet.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hdr.h"
#include "extern.h"


void
getin(char  **wrd1,char **wrd2)		/* get command from user        */
								/* no prompt, usually           */
{
	char   *s;
	static char wd1buf[MAXSTR], wd2buf[MAXSTR];
	int     first, numch;

	*wrd1 = wd1buf;				/* return ptr to internal str */
	*wrd2 = wd2buf;
	wd2buf[0] = 0;				/* in case it isn't set here */
	for (s = wd1buf, first = 1, numch = 0;;) {
		if ((*s = getchar()) >= 'A' && *s <= 'Z')
			*s = *s - ('A' - 'a');
		/* convert to upper case */
		switch (*s) {			/* start reading from user */
		case '\n':
			*s = 0;
			return;
		case ' ':
			if (s == wd1buf || s == wd2buf)	/* initial blank */
				continue;
			*s = 0;
			if (first) {		/* finished 1st wd; start 2nd */
				first = numch = 0;
				s = wd2buf;
				break;
			} else {		/* finished 2nd word */
				FLUSHLINE;
				*s = 0;
				return;
			}
		case EOF:
			printf("user closed input stream, quitting...\n");
			exit(0);
		default:
			if (++numch >= MAXSTR) {	/* string too long */
				printf("Give me a break!!\n");
				wd1buf[0] = wd2buf[0] = 0;
				FLUSHLINE;
				return;
			}
			s++;
		}
	}
}

int
yes(int x,int y,int z)			/* confirm with rspeak          */
{
	int     result = TRUE;	/* pacify gcc */
	int    ch;
	for (;;) {
		rspeak(x);	/* tell him what we want */
		if ((ch = getchar()) == 'y')
			result = TRUE;
		else if (ch == 'n')
			result = FALSE;
		else if (ch == EOF) {
			printf("user closed input stream, quitting...\n");
			exit(0);
		}
		FLUSHLINE;
		if (ch == 'y' || ch == 'n')
			break;
		printf("Please answer the question.\n");
	}
	if (result == TRUE)
		rspeak(y);
	if (result == FALSE)
		rspeak(z);
	return (result);
}

int
yesm(int x,int y,int z)			/* confirm with mspeak          */
{
	int     result = TRUE;	/* pacify gcc */
	int    ch;
	for (;;) {
		mspeak(x);	/* tell him what we want */
		if ((ch = getchar()) == 'y')
			result = TRUE;
		else if (ch == 'n')
			result = FALSE;
		else if (ch == EOF) {
			printf("user closed input stream, quitting...\n");
			exit(0);
		}
		FLUSHLINE;
		if (ch == 'y' || ch == 'n')
			break;
		printf("Please answer the question.\n");
	}
	if (result == TRUE)
		mspeak(y);
	if (result == FALSE)
		mspeak(z);
	return (result);
}
/* FILE *inbuf,*outbuf; */

char   *inptr;			/* Pointer into virtual disk    */

int     outsw = 0;		/* putting stuff to data file?  */

extern const char    iotape[] = "Ax3F'\003tt$8h\315qer*h\017nGKrX\207:!l";
const char   *tape = iotape;		/* pointer to encryption tape   */

int
next()
{				/* next virtual char, bump adr  */
	int     ch;

	ch = (*inptr ^ random()) & 0xFF;	/* Decrypt input data           */
	if (outsw) {		/* putting data in tmp file     */
		if (*tape == 0)
			tape = iotape;	/* rewind encryption tape       */
		*inptr = ch ^ *tape++;	/* re-encrypt and replace value */
	}
	inptr++;
	return (ch);
}

char    breakch;		/* tell which char ended rnum   */

void
rdata()
{				/* "read" data from virtual file */
	int     sect;
	char    ch;

	inptr = data_file;	/* Pointer to virtual data file */
	srandom(SEED);		/* which is lightly encrypted.  */

	clsses = 1;
	for (;;) {		/* read data sections           */
		sect = next() - '0';	/* 1st digit of section number  */
#ifdef VERBOSE
		printf("Section %c", sect + '0');
#endif
		if ((ch = next()) != LF) {	/* is there a second digit?     */
			FLUSHLF;
#ifdef VERBOSE
			putchar(ch);
#endif
			sect = 10 * sect + ch - '0';
		}
#ifdef VERBOSE
		putchar('\n');
#endif
		switch (sect) {
		case 0:	/* finished reading database    */
			return;
		case 1:	/* long form descriptions       */
			rdesc(1);
			break;
		case 2:	/* short form descriptions      */
			rdesc(2);
			break;
		case 3:	/* travel table                 */
			rtrav();
			break;
		case 4:	/* vocabulary                   */
			rvoc();
			break;
		case 5:	/* object descriptions          */
			rdesc(5);
			break;
		case 6:	/* arbitrary messages           */
			rdesc(6);
			break;
		case 7:	/* object locations             */
			rlocs();
			break;
		case 8:	/* action defaults              */
			rdflt();
			break;
		case 9:	/* liquid assets                */
			rliq();
			break;
		case 10:	/* class messages               */
			rdesc(10);
			break;
		case 11:	/* hints                        */
			rhints();
			break;
		case 12:	/* magic messages               */
			rdesc(12);
			break;
		default:
			printf("Invalid data section number: %d\n", sect);
			for (;;)
				putchar(next());
		}
		if (breakch != LF)	/* routines return after "-1"   */
			FLUSHLF;
	}
}

char    nbf[12];


int
rnum()
{				/* read initial location num    */
	char   *s;
	tape = iotape;		/* restart encryption tape      */
	for (s = nbf, *s = 0;; s++)
		if ((*s = next()) == TAB || *s == '\n' || *s == LF)
			break;
	breakch = *s;		/* save char for rtrav()        */
	*s = 0;			/* got the number as ascii      */
	if (nbf[0] == '-')
		return (-1);	/* end of data                  */
	return (atoi(nbf));	/* convert it to integer        */
}

char   *seekhere;

void
rdesc(int sect)			/* read description-format msgs */
{
	int     locc;
	char   *seekstart, *maystart;

	seekhere = inptr;	/* Where are we in virtual file? */
	outsw = 1;		/* these msgs go into tmp file  */
	for (oldloc = -1, seekstart = seekhere;;) {
		maystart = inptr;	/* maybe starting new entry     */
		if ((locc = rnum()) != oldloc && oldloc >= 0	/* finished msg */
		    && !(sect == 5 && (locc == 0 || locc >= 100))) {	/* unless sect 5 */
			switch (sect) {	/* now put it into right table  */
			case 1:/* long descriptions            */
				ltext[oldloc].seekadr = seekhere;
				ltext[oldloc].txtlen = maystart - seekstart;
				break;
			case 2:/* short descriptions           */
				stext[oldloc].seekadr = seekhere;
				stext[oldloc].txtlen = maystart - seekstart;
				break;
			case 5:/* object descriptions          */
				ptext[oldloc].seekadr = seekhere;
				ptext[oldloc].txtlen = maystart - seekstart;
				break;
			case 6:/* random messages              */
				if (oldloc >= RTXSIZ) 
					errx(1,"Too many random messages");
				rtext[oldloc].seekadr = seekhere;
				rtext[oldloc].txtlen = maystart - seekstart;
				break;
			case 10:	/* class messages               */
				ctext[clsses].seekadr = seekhere;
				ctext[clsses].txtlen = maystart - seekstart;
				cval[clsses++] = oldloc;
				break;
			case 12:	/* magic messages               */
				if (oldloc >= MAGSIZ)
					errx(1,"Too many magic messages");
				mtext[oldloc].seekadr = seekhere;
				mtext[oldloc].txtlen = maystart - seekstart;
				break;
			default:
				errx(1,"rdesc called with bad section");
			}
			seekhere += maystart - seekstart;
		}
		if (locc < 0) {
			outsw = 0;	/* turn off output              */
			seekhere += 3;	/* -1<delimiter>                */
			return;
		}
		if (sect != 5 || (locc > 0 && locc < 100)) {
			if (oldloc != locc)	/* starting a new message       */
				seekstart = maystart;
			oldloc = locc;
		}
		FLUSHLF;	/* scan the line                */
	}
}

void
rtrav()
{				/* read travel table            */
	int     locc;
	struct travlist *t = NULL;
	char   *s;
	char    buf[12];
	int     len, m, n, entries = 0;

	for (oldloc = -1;;) {	/* get another line             */
		if ((locc = rnum()) != oldloc && oldloc >= 0) {	/* end of entry */
			t->next = 0;	/* terminate the old entry      */
			/* printf("%d:%d entries\n",oldloc,entries);       */
			/* twrite(oldloc);                                 */
		}
		if (locc == -1)
			return;
		if (locc != oldloc) {	/* getting a new entry         */
			t = travel[locc] = (struct travlist *) malloc(sizeof(struct travlist));
			if ( t == NULL)
				err(1, NULL);
			/* printf("New travel list for %d\n",locc);        */
			entries = 0;
			oldloc = locc;
		}
		for (s = buf;; s++)	/* get the newloc number /ASCII */
			if ((*s = next()) == TAB || *s == LF)
				break;
		*s = 0;
		len = slength(buf) - 1;	/* quad long number handling    */
		/* printf("Newloc: %s (%d chars)\n",buf,len);              */
		if (len < 4) {	/* no "m" conditions            */
			m = 0;
			n = atoi(buf);	/* newloc mod 1000 = newloc     */
		} else {	/* a long integer               */
			n = atoi(buf + len - 3);
			buf[len - 3] = 0;	/* terminate newloc/1000        */
			m = atoi(buf);
		}
		while (breakch != LF) {	/* only do one line at a time   */
			if (entries++) {
				t = t->next = (struct travlist *) malloc(sizeof(struct travlist));
				if (t == NULL)
					err(1, NULL);
			}
			t->tverb = rnum();	/* get verb from the file       */
			t->tloc = n;	/* table entry mod 1000         */
			t->conditions = m;	/* table entry / 1000           */
			/* printf("entry %d for %d\n",entries,locc);       */
		}
	}
}
#ifdef DEBUG

void
twrite(loq)			/* travel options from this loc */
	int     loq;
{
	struct travlist *t;
	printf("If");
	festival_speak(&ltext[loq]);
	printf("then\n");
	for (t = travel[loq]; t != 0; t = t->next) {
		printf("verb %d takes you to ", t->tverb);
		if (t->tloc <= 300)
			festival_speak(&ltext[t->tloc]);
		else
			if (t->tloc <= 500)
				printf("special code %d\n", t->tloc - 300);
			else
				rspeak(t->tloc - 500);
		printf("under conditions %d\n", t->conditions);
	}
}
#endif				/* DEBUG */

void
rvoc()
{
	char   *s;		/* read the vocabulary          */
	int     index;
	char    buf[6];
	for (;;) {
		index = rnum();
		if (index < 0)
			break;
		for (s = buf, *s = 0;; s++)	/* get the word                 */
			if ((*s = next()) == TAB || *s == '\n' || *s == LF
			    || *s == ' ')
				break;
		/* terminate word with newline, LF, tab, blank  */
		if (*s != '\n' && *s != LF)
			FLUSHLF;/* can be comments    */
		*s = 0;
		/* printf("\"%s\"=%d\n",buf,index); */
		vocab(buf, -2, index);
	}
/*	prht();	*/
}


void
rlocs()
{				/* initial object locations     */
	for (;;) {
		if ((obj = rnum()) < 0)
			break;
		plac[obj] = rnum();	/* initial loc for this obj     */
		if (breakch == TAB)	/* there's another entry        */
			fixd[obj] = rnum();
		else
			fixd[obj] = 0;
	}
}

void
rdflt()
{				/* default verb messages        */
	for (;;) {
		if ((verb = rnum()) < 0)
			break;
		actspk[verb] = rnum();
	}
}

void
rliq()
{				/* liquid assets &c: cond bits  */
	int     bitnum;
	for (;;) {		/* read new bit list            */
		if ((bitnum = rnum()) < 0)
			break;
		for (;;) {	/* read locs for bits           */
			cond[rnum()] |= setbit[bitnum];
			if (breakch == LF)
				break;
		}
	}
}

void
rhints()
{
	int     hintnum, i;
	hntmax = 0;
	for (;;) {
		if ((hintnum = rnum()) < 0)
			break;
		for (i = 1; i < 5; i++)
			hints[hintnum][i] = rnum();
		if (hintnum > hntmax)
			hntmax = hintnum;
	}
}


void
rspeak(int msg)
{
	if (msg != 0)
		festival_speak(&rtext[msg]);
}


void
mspeak(int msg)
{
	if (msg != 0)
		festival_speak(&mtext[msg]);
}


void
speak(const struct text *msg)			/* read, decrypt, and print a message (not
				 * ptext)      */
				 /* msg is a pointer to seek address and length
				 * of mess */
{
	char   *s, nonfirst;

	s = msg->seekadr;
	nonfirst = 0;
	while (s - msg->seekadr < msg->txtlen) {	/* read a line at a time */
		tape = iotape;	/* restart decryption tape      */
		while ((*s++ ^ *tape++) != TAB);	/* read past loc num       */
		/* assume tape is longer than location number           */
		/* plus the lookahead put together                    */
		if ((*s ^ *tape) == '>' &&
		    (*(s + 1) ^ *(tape + 1)) == '$' &&
		    (*(s + 2) ^ *(tape + 2)) == '<')
			break;
		if (blklin && !nonfirst++)
			putchar('\n');
		do {
			if (*tape == 0)
				tape = iotape;	/* rewind decryp tape */
			putchar(*s ^ *tape);
		} while ((*s++ ^ *tape++) != LF);	/* better end with LF   */
	}
}


void
pspeak(int m,int skip)			/* read, decrypt an print a ptext message              */
		/* msg is the number of all the p msgs for
				 * this place  */
		/* assumes object 1 doesn't have prop 1, obj 2
				 * no prop 2 &c */
{
	char   *s, nonfirst;
	char   *numst, save;
	struct text *msg;
	char   *tbuf;

	msg = &ptext[m];
	if ((tbuf = (char *) malloc(msg->txtlen + 1)) == NULL)
		err(1, NULL);
	memcpy(tbuf, msg->seekadr, msg->txtlen + 1);	/* Room to null */
	s = tbuf;

	nonfirst = 0;
	while (s - tbuf < msg->txtlen) {	/* read line at a time */
		tape = iotape;	/* restart decryption tape      */
		for (numst = s; (*s ^= *tape++) != TAB; s++);	/* get number  */

		save = *s;	/* Temporarily trash the string (cringe) */
		*s++ = 0;	/* decrypting number within the string          */

		if (atoi(numst) != 100 * skip && skip >= 0) {
			while ((*s++ ^ *tape++) != LF)	/* flush the line    */
				if (*tape == 0)
					tape = iotape;
			continue;
		}
		if ((*s ^ *tape) == '>' && (*(s + 1) ^ *(tape + 1)) == '$' &&
		    (*(s + 2) ^ *(tape + 2)) == '<')
			break;
		if (blklin && !nonfirst++)
			putchar('\n');
		do {
			if (*tape == 0)
				tape = iotape;
			putchar(*s ^ *tape);
		} while ((*s++ ^ *tape++) != LF);	/* better end with LF   */
		if (skip < 0)
			break;
	}
	free(tbuf);
}
