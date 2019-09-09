#include "ResManager.h"
#include "BitMap.h"
#include "macro.h"
#include "Player.h"

ResManager::ResManager()
{

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

void ResManager::DrawScene(HDC hdc,int x) //화면 마지막에 그려주는애
{//             어디에/ 비트맵 어디서/      /비트맵 어디까지
	BitBlt(hdc, x, 0, WIN_X, WIN_Y, m_hMemDC,0, 0, SRCCOPY);
}


void ResManager::Init(HDC hdc)
{
	InitBackBuffer(hdc);
	m_iDisplayX = 0;
	m_pPlayer = nullptr;
	BitMap* pNewBit;

	string storagePathUi[RES_TYPE_UI_END] = { "RES\\star1.bmp","RES\\star2.bmp","RES\\icon.bmp","RES\\miter.bmp" };

	for (int i = 0; i < RES_TYPE_UI_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathUi[i]);
		m_mapBitMap.insert(make_pair(storagePathUi[i], pNewBit));
	}

	string storagePathBackground[RES_TYPE_BACKGROUND_END] = { "RES\\back.bmp","RES\\back_deco.bmp","RES\\back_normal.bmp","RES\\back_normal2.bmp" };

	for (int i = 0; i < RES_TYPE_BACKGROUND_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathBackground[i]);
		m_mapBitMap.insert(make_pair(storagePathBackground[i], pNewBit));
	}

	string storagePathPlayer[RES_TYPE_PLAYER_END] = { "RES\\player0.bmp","RES\\player1.bmp","RES\\player2.bmp","RES\\win.bmp","RES\\win2.bmp" ,"RES\\die.bmp" };

	for (int i = 0; i < RES_TYPE_PLAYER_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathPlayer[i]);
		m_mapBitMap.insert(make_pair(storagePathPlayer[i], pNewBit));
	}

	string storagePathObject[RES_TYPE_OBJECT_END] = { "RES\\end.bmp","RES\\cash.bmp","RES\\front.bmp","RES\\front2.bmp","RES\\enemy_1b.bmp" ,"RES\\enemy_1f.bmp","RES\\enemy_b.bmp","RES\\enemy_f.bmp" };

	for (int i = 0; i < RES_TYPE_OBJECT_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathObject[i]);
		m_mapBitMap.insert(make_pair(storagePathObject[i], pNewBit));
	}
}

BitMap* ResManager::GetBitMap(string strFileName)
{
	return m_mapBitMap[strFileName];
}

void ResManager::Release()
{
	for (auto iter = m_mapBitMap.begin(); iter != m_mapBitMap.end(); ++iter)
	{
		SAFE_DELETE((*iter).second);
	}
}
