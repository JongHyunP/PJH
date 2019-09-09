#include "ResManager.h"
#include "BitMap.h"
#include "macro.h"

ResManager::ResManager()
{
	m_iDisplayX = 0;
}


ResManager::~ResManager()
{
}

void ResManager::InitBackBuffer(HDC hdc)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = CreateCompatibleBitmap(hdc, 800, 600);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);
}

HDC ResManager::GetBackBuffer()
{
	return m_hMemDC;
}

void ResManager::DrawScene(HDC hdc) //화면 마지막에 그려주는애
{
	BitBlt(hdc, 0, 0, WIN_X, WIN_Y, m_hMemDC, 0, 0, SRCCOPY);
}

void ResManager::Init(HDC hdc)
{
	InitBackBuffer(hdc);

	BitMap* pNewBit;
	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\back.bmp");
	m_mapBitMap.insert(make_pair("RES\\back.bmp" , pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\back_deco.bmp");
	m_mapBitMap.insert(make_pair("RES\\back_deco.bmp", pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\back_normal.bmp");
	m_mapBitMap.insert(make_pair("RES\\back_normal.bmp", pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\back_normal2.bmp");
	m_mapBitMap.insert(make_pair("RES\\back_normal2.bmp", pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\player0.bmp");
	m_mapBitMap.insert(make_pair("RES\\player0.bmp", pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\player1.bmp");
	m_mapBitMap.insert(make_pair("RES\\player1.bmp", pNewBit));

	pNewBit = new BitMap();
	pNewBit->Init(hdc, "RES\\player2.bmp");
	m_mapBitMap.insert(make_pair("RES\\player2.bmp", pNewBit));
}

BitMap* ResManager::GetBitMap(string strFileName)
{
	return m_mapBitMap[strFileName];
}

void ResManager::Release()
{

}
