#include <stdlib.h>
#include <string.h>
#include <switch.h>
#include <time.h>

#define RANDOM ((rand() % 0x1000000) | 0xff000000)

void initGfx();
void drawGfx(u32 x, u32 y, u32 col);
void closeGfx();