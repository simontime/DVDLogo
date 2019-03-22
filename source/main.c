#include "gfx.h"

int main() {
	initGfx();

	u32 xpos = 0, ypos = 0, speed = 1, col = RANDOM;
	bool dirUp = false, dirRight = true;

	srand(time(NULL));

	while (appletMainLoop()) {
		hidScanInput();
		u64 key = hidKeysDown(CONTROLLER_P1_AUTO);

		if (key & KEY_A) {
			switch (speed) {
				case 1:
					speed = 3;
					break;
				case 3:
					speed = 6;
					break;
				case 6:
					speed = 24;
					break;
				case 24:
					speed = 1;
					break;
			}
		}

		if (key & KEY_PLUS) break;

		dirUp    ? (ypos -= speed) : (ypos += speed);
		dirRight ? (xpos += speed) : (xpos -= speed);

		if (xpos <= 0)    { xpos = 0;    dirRight = true;  col = RANDOM; }
		if (ypos <= 0)    { ypos = 0;    dirUp    = false; col = RANDOM; }
		if (xpos >= 1080) { xpos = 1080; dirRight = false; col = RANDOM; }
		if (ypos >= 600)  { ypos = 600;  dirUp    = true;  col = RANDOM; }

		drawGfx(xpos, ypos, col);
	}

	closeGfx();

	return 0;
}