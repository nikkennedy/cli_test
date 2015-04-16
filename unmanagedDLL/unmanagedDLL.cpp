// This is the main DLL file.

#include "unmanagedDLL.h"

UnmanagedWrapper::UnmanagedWrapper()
{
	m_cPtr = new Unmanaged();
}

int UnmanagedWrapper::callTest()
{
	return m_cPtr->callTest();
}

int UnmanagedWrapper::callTest(int num)
{
	return m_cPtr->callTest(num);
}

int UnmanagedWrapper::SDL_GetWindowID(int width, int height)
{
	return m_cPtr->SDL_GetWindowID(width, height);
}

int UnmanagedWrapper::resize(int w, int h)
{
	return m_cPtr->resize(w, h);
}