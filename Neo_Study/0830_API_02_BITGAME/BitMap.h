#pragma once
#include <Windows.h>

class BitMap
{
	HDC m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;

public:
	BitMap();
	~BitMap();

	void Init(HDC hdc, HINSTANCE hInst, int id);
	void Draw(HDC hdc, int x, int y, int cx, int cy);
	void Release();
};

