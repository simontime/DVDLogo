#include "gfx.h"

int main() {
	initGfx();
	
	u32 xpos = 0, ypos = 0, col = RANDOM;
	bool dirUp = false, dirRight = true;
	
    while (appletMainLoop()) {
		hidScanInput();
		
		if (hidKeysHeld(CONTROLLER_P1_AUTO) & KEY_PLUS) break;
		
		dirUp    ? ypos-- : ypos++;
		dirRight ? xpos++ : xpos--;

		if (xpos <= 0)    { xpos = 0;    dirRight = true;  col = RANDOM; }
		if (ypos <= 0)    { ypos = 0;    dirUp    = false; col = RANDOM; }
		if (xpos >= 1080) { xpos = 1080; dirRight = false; col = RANDOM; }
		if (ypos >= 600)  { ypos = 600;  dirUp    = true;  col = RANDOM; }

		drawGfx(xpos, ypos, col);
    }

    closeGfx();

    return 0;
}