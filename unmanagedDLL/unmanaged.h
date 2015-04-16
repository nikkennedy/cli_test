#ifndef _UNMANAGED_H_
#define _UNMANAGED_H_

class Unmanaged
{
private:
	int m_width = 200;
	int m_height = 100;

public:
	Unmanaged();
	~Unmanaged();

	int callTest();
	int callTest(int num);

	int SDL_GetWindowID();
};

#endif