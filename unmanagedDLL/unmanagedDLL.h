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

	int SDL_GetWindowID();

private:
	Unmanaged *m_cPtr;

};

