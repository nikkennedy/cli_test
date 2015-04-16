#include <stdio.h>
#include "unmanaged.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

Unmanaged::Unmanaged()
{
	printf("unmanaged class created.\n");
}

Unmanaged::~Unmanaged()
{
	printf("unmanaged class destroyed.\n");
}

int Unmanaged::callTest()
{
	printf("callTest called with no params\n");
	return 0;
}

int Unmanaged::callTest(int num)
{
	printf("callTest called with number %d\n", num);
	return num;
}

int Unmanaged::SDL_GetWindowID()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("error");
		return 0;
	}

	SDL_Window* windowID = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

	SDL_SysWMinfo info;

	SDL_VERSION(&info.version);
	SDL_GetWindowWMInfo(windowID, &info);

	int _hwnd = (int) info.info.win.window;

	if (windowID == NULL)
		return 0;

	return _hwnd;
}