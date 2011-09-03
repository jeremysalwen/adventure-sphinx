#ifndef FESTIVAL_DRIVER_H
#define FESTIVAL_DRIVER_H

void festival_speak(const struct text *msg);
void initAdventureFestival();
void festival_printf(const char *format, ...);
#endif
