#pragma once
#include <Windows.h>
#include <string>

using namespace std;

class BitMap
{
	HDC m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;
	SIZE	m_size;

public:
	BitMap();
	~BitMap();

	//void Init(HDC hdc, HINSTANCE hInst, int id);
	void Init(HDC hdc, string Filename);
	void Draw(HDC hdc, int x, int y);
	void Release();
};