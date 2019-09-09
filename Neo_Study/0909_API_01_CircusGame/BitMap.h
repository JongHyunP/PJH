#pragma once
#include <Windows.h>
#include <string>
using namespace std;

class BitMap
{
private:
	HDC m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;
	SIZE	m_size;
public:
	void Init(HDC hdc, string strFileName);
	void Draw(HDC hdc, int x, int y , bool bTrans);
	void Release();


	BitMap();
	~BitMap();
};

