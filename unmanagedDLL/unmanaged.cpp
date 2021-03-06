#include <stdio.h>
#include "unmanaged.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <gl\GL.h>


SDL_GLContext m_GLContext;
SDL_Window* m_windowID = NULL;
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
	SDL_Event e;

	// if below is uncommented, window can not be resized, must be created in same thread as window manager
//	m_windowID = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

	m_GLContext = SDL_GL_CreateContext(m_windowID);

	if (m_GLContext == NULL)
		return 0;
	float r = 1.0;
	while (1)
	{
		glViewport((GLint)0, (GLint)0, (GLsizei)(g_w), (GLsizei)(g_h));

		glClearColor(r, r, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type) {
			case SDL_KEYDOWN:
				printf("Key Down\n");
				break;
			default:
				break;
				//printf("Unknown event.\n");
			}
		}


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

	SDL_SetWindowSize(m_windowID, w, h);
	
	return 1;
}

int Unmanaged::SDL_GetWindowID(int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("error");
		return 0;
	}

	SDL_EventState(SDL_WINDOWEVENT, SDL_IGNORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5); // was 8, 8, 8, 8
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 1);

	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24); // need good resolution depth buffer

	m_width = 500;// width;
	m_height = 500;// height;

	// if this window is created in same thread as the context, then main window can not be resized!
	m_windowID = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

	startRenderThread();

	while (m_windowID == NULL) {};

	SDL_SysWMinfo info;

	SDL_VERSION(&info.version);
	SDL_GetWindowWMInfo(m_windowID, &info);

	int _hwnd = (int) info.info.win.window;

	if (m_windowID == NULL)
		return 0;

	return _hwnd;
}