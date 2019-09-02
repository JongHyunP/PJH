#include "BitMap.h"


BitMap::BitMap()
{

}
BitMap::~BitMap()
{

}
void BitMap::Init(HDC hdc, HINSTANCE hInst,int id)
//void BitMap::Init(HDC hdc, string Filename)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(id));
	//m_hBitMap = (HBITMAP)LoadImage(NULL, "Res\\"+Filename +".bmp", IMAGE_BITMAP, 0, 0 , LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

	BITMAP bitmap;
	GetObject(m_hBitMap, sizeof(bitmap), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y)
{
	BitBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
}

void BitMap::Release()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}
