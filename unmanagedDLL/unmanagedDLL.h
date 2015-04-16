#pragma once

#include "unmanaged.h"

using namespace System;

public ref class UnmanagedWrapper
{
public:
	UnmanagedWrapper();

	// wrapper methods
	int callTest();
	int callTest(int num);

	int resize(int w, int h);

	int SDL_GetWindowID(int width, int height);

private:
	Unmanaged *m_cPtr;

};

