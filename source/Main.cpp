#include "Gfx.hpp"

int main()
{
	/* Get a random colour, ORed with 0xff000000 for 100% opacity */
	auto getRandom = []() {
		return (std::rand() % 0x1000000) | 0xff000000;
	};
	
	u32 xpos = 0, ypos = 0, speed = 1, col = getRandom();
	u64 key;
	bool dirUp = false, dirRight = true;
	touchPosition touch;
	
	Gfx::Init();

	/* Seed rand() */
	std::srand(std::time(NULL));

	while (appletMainLoop())
	{
		hidScanInput();
		key = hidKeysDown(CONTROLLER_P1_AUTO);

		if (key & KEY_A)
		{
			/* Adjust speed */
			switch (speed)
			{
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

		if (key & KEY_PLUS)
			break;

		/* Direction control */
		xpos += dirRight ?  speed : -speed;
		ypos += dirUp    ? -speed :  speed;

		/* Touch screen stuff */
		if (hidTouchCount())
		{
			hidTouchRead(&touch, 0);
			
			xpos = touch.px - LogoWidth  / 2;
			ypos = touch.py - LogoHeight / 2;
		}
		
		/* Check bounds */
		if (xpos <= 0)
		{
			xpos     = 0;
			dirRight = true;
			col      = getRandom();
		}
		
		if (ypos <= 0)
		{
			ypos  = 0;
			dirUp = false;
			col   = getRandom();
		}
		
		if (xpos >= ScreenWidth - LogoWidth)
		{
			xpos     = ScreenWidth - LogoWidth;
			dirRight = false;
			col      = getRandom();
		}
		
		if (ypos >= ScreenHeight - LogoHeight)
		{
			ypos  = ScreenHeight - LogoHeight;
			dirUp = true;
			col   = getRandom();
		}

		Gfx::Draw(xpos, ypos, col);
	}

	Gfx::Close();

	return 0;
}
