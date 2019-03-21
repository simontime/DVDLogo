#include <stdlib.h>
#include <string.h>
#include <switch.h>

#define RANDOM ((rand() % 16777216) | 0xff000000)

void initGfx();
void drawGfx(u32 x, u32 y, u32 col);
void closeGfx();