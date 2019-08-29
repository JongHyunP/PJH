#pragma once
#include <Windows.h>

class Input
{
	int len;
    TCHAR str[256];
public:
	Input();
	~Input();
	void PlayerInputWord(WPARAM wParam);
	void PlayerInputWordPaint(HDC hdc);
};

