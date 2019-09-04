#include "BitMap.h"



BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::Init(HDC hdc, string Filename)
{
	m_MemDC[0] = CreateCompatibleDC(hdc);
	m_hBitMap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld[0] = (HBITMAP)SelectObject(m_MemDC[0], m_hBitMap[0]);

	m_MemDC[1] = CreateCompatibleDC(m_MemDC[0]);
	m_hBitMap[1] = (HBITMAP)LoadImage(NULL, Filename.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOld[1] = (HBITMAP)SelectObject(m_MemDC[1], m_hBitMap[1]);

	BITMAP bitmap;
	GetObject(m_hBitMap[1], sizeof(bitmap), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y)
{
	//BitBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);

	BitBlt(m_MemDC[0], 0, 0, 1024, 768, m_MemDC[1], 0, 0, SRCCOPY);
	TransparentBlt(m_MemDC[0], 0, 0, m_size.cx, m_size.cy, m_MemDC[1], 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
	BitBlt(hdc, 0, 0, 1024, 768, m_MemDC[0], 0, 0, SRCCOPY);
}

void BitMap::Release()
{
	SelectObject(m_MemDC[1], m_hOld[1]);
	DeleteObject(m_hBitMap[1]);
	DeleteDC(m_MemDC[1]);

	SelectObject(m_MemDC[0], m_hOld[0]);
	DeleteObject(m_hBitMap[0]);
	DeleteDC(m_MemDC[0]);
}