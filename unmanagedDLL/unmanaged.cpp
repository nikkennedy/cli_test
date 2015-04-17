#include <stdio.h>
#include "unmanaged.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <gl\GL.h>


SDL_GLContext m_GLContext;
SDL_Window* m_windowID;
int g_w, g_h;

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

int _main_thread(void* data)
{
	m_GLContext = SDL_GL_CreateContext(m_windowID);

	if (m_GLContext == NULL)
		return 0;
	float r = 1.0;
	while (1)
	{
		glViewport((GLint)0, (GLint)0, (GLsizei)(g_w), (GLsizei)(g_h));

		glClearColor(r, r, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(m_windowID);
		r -= 0.01;
		if (r <= 0) r = 1.0;
		SDL_Delay(100);
	}

	return 1;
}

int Unmanaged::startRenderThread()
{
	SDL_Thread* mainThread = SDL_CreateThread(_main_thread, "MainThread", NULL);

	return 1;
}

int Unmanaged::resize(int w, int h)
{
	g_w = w;
	g_h = h;

	printf("Resizing...\n");

//	SDL_SetWindowSize(m_windowID, w, h);
	
	return 1;
}

int Unmanaged::SDL_GetWindowID(int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("error");
		return 0;
	}

	m_width = width;
	m_height = height;

	m_windowID = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

	startRenderThread();

	SDL_SysWMinfo info;

	SDL_VERSION(&info.version);
	SDL_GetWindowWMInfo(m_windowID, &info);

	int _hwnd = (int) info.info.win.window;

	if (m_windowID == NULL)
		return 0;

	return _hwnd;
}