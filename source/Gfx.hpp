#include <algorithm>
#include <cstdlib>
#include <ctime>

#include <switch.h>

constexpr u32 ScreenWidth  = 1280;
constexpr u32 ScreenHeight = 720;

constexpr u32 LogoWidth  = 200;
constexpr u32 LogoHeight = 120;

namespace Gfx
{
	void Init();
	void Draw(u32 x, u32 y, u32 col);
	void Close();
}
