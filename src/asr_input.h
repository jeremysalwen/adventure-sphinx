#ifndef ASR_INPUT_H
#define ASR_INPUT_H


#include "portaudio.h"
#include "pthread.h"
#include "math.h"
#include "extern.h"
#include <err.h>

#ifndef MODELDIR
#define MODELDIR "/usr/share/pocketsphinx/model"
#endif

#define GRAMDIR PACKAGE_DATA_DIR "/grammars"
void ASR_init(int startThresh, int stopThresh);

void asr_getin(char ** wrd1,char **wrd2);
int asr_yes(int x, int y, int z);
int asr_yesm(int x, int y, int z);
#endif /* ASR_INPUT_H */
