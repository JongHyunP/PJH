#include "Input.h"



Input::Input()
{
	
}


Input::~Input()
{
}

void Input::PlayerInputWord(WPARAM wParam)
{
	len = lstrlen(str);
	str[len] = (TCHAR)wParam;
	str[len + 1] = 0;
}

void Input::PlayerInputWordPaint(HDC hdc)
{
	TextOut(hdc, 400, 400, str, lstrlen(str));
}
