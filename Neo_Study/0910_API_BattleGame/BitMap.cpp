#include "BitMap.h"

BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::Init(HDC hdc, string strFileName)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = (HBITMAP)LoadImage(NULL, strFileName.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);
}

void BitMap::Draw(HDC hdc, int x, int y,int cx1,int cy1, int cx2, int cy2,bool bTrans)
{
	if (bTrans)
		TransparentBlt(hdc, x, y, cx2, cy2, m_hMemDC, 0, 0, cx2, cy2, RGB(255, 0, 255));
	else
		BitBlt(hdc, x, y, cx2, cy2, m_hMemDC, 0, 0, SRCCOPY);
}

void BitMap::Release()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}
