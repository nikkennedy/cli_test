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

int UnmanagedWrapper::SDL_GetWindowID()
{
	return m_cPtr->SDL_GetWindowID();
}