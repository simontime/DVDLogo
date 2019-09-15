#include "Dvd.hpp"
#include "Gfx.hpp"

namespace Gfx
{
	static Framebuffer sFb;
	static u32 sStride, *sFrameBuf;

	void Init()
	{
		framebufferCreate(&sFb, nwindowGetDefault(), ScreenWidth, ScreenHeight, PIXEL_FORMAT_RGBA_8888, 2);
		framebufferMakeLinear(&sFb);
		sFrameBuf = (u32 *)framebufferBegin(&sFb, &sStride);
		std::fill(sFrameBuf, sFrameBuf + (sStride * ScreenHeight), 0);
		framebufferEnd(&sFb);
	}
	
	void Draw(u32 x, u32 y, u32 col)
	{
		u32 bit = 0, offset = 0, px, xPos, yPos;
		
		std::fill(sFrameBuf, sFrameBuf + (ScreenWidth * ScreenHeight * 4), 0);
		
		/* Draw 1-bit DVD logo to framebuffer */
		for (yPos = y; yPos < y + LogoHeight; yPos++)
		{
			for (xPos = x; xPos < x + LogoWidth; xPos++)
			{
				/* Get byte at offset, get bit at count */
				px = (Logo[offset] >> (bit++ % 8)) & 1;
				
				/* Fill pixel in framebuffer */
				sFrameBuf[yPos * ScreenWidth + xPos] = px ? col : px;
				
				/* Increment offset after 8 bits read, reset bit counter */
				if (bit % 8 == 0)
				{
					offset++;
					bit = 0;
				}
			}
		}
	
		framebufferBegin(&sFb, &sStride);
		framebufferEnd(&sFb);
	}
	
	void Close()
	{
		framebufferClose(&sFb);
	}
}
