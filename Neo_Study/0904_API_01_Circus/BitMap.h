#pragma once
#include <Windows.h>
#include <string>

using namespace std;

class BitMap
{
	HDC m_MemDC[2];
	HBITMAP m_hBitMap[2];
	HBITMAP m_hOld[2];

	SIZE	m_size;
public:
	BitMap();
	~BitMap();

	void Init(HDC hdc, string Filename);
	void Draw(HDC hdc, int PosX, int PosY, int transX, int transY);
	void Release();
};

