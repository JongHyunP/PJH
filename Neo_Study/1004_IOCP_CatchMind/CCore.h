#pragma once
#include "value.h"

class CCore
{
	DECLARE_SINGLE(CCore)
public:
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Update();
	void Input(POINT pt);
};

