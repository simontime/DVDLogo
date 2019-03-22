#include "dvd.h"
#include "gfx.h"

static Framebuffer fb;
static u32 stride, *framebuf;

void initGfx() {
	framebufferCreate(&fb, nwindowGetDefault(), 1280, 720, PIXEL_FORMAT_RGBA_8888, 2);
	framebufferMakeLinear(&fb);
	framebuf = (u32 *)framebufferBegin(&fb, &stride);
	memset(framebuf, 0, stride * 720);
	framebufferEnd(&fb);
}

void drawGfx(u32 x, u32 y, u32 col) {
	int offset = 0;

	memset(framebuf, 0, 1280 * 720 * 4);

	for (u32 yPos = y; yPos < y + 120; yPos++)
		for (u32 xPos = x; xPos < x + 200; xPos++) {
			u8 px = dvd[offset++];
			framebuf[yPos * 1280 + xPos] = px > 1 ? col : px;
		}

	framebufferBegin(&fb, &stride);
	framebufferEnd(&fb);
}

void closeGfx() {
	framebufferClose(&fb);
}