#include "ResManager.h"
#include "BitMap.h"
#include "mecro.h"

ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}

void ResManager::InitBackBuffer(HDC hdc)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);
}

HDC ResManager::GetBackBuffer()
{
	return m_hMemDC;
}

void ResManager::DrawScene(HDC hdc)
{
	BitBlt(hdc, 0, 0, 1024, 768, m_hMemDC, 0, 0, SRCCOPY);
}


void ResManager::Init(HDC hdc)
{
	string storagePathUi[RES_TYPE_UI_END] = { "Res\\star1.bmp","Res\\star2.bmp","Res\\icon.bmp","Res\\miter.bmp" };

	for (int i = 0; i < RES_TYPE_UI_END; i++)
	{
		m_pBitMapUi[i] = new BitMap();
		m_pBitMapUi[i]->Init(hdc, storagePathUi[i]);
	}

	string storagePathBackground[RES_TYPE_BACKGROUND_END] = { "Res\\back.bmp","Res\\back_deco.bmp","Res\\back_normal.bmp","Res\\back_normal2.bmp" };

	for (int i = 0; i < RES_TYPE_BACKGROUND_END; i++)
	{
		m_pBitMapBackground[i] = new BitMap();
		m_pBitMapBackground[i]->Init(hdc, storagePathBackground[i]);
	}

	string storagePathPlayer[RES_TYPE_PLAYER_END] = { "Res\\player0.bmp","Res\\player1.bmp","Res\\player2.bmp","Res\\win.bmp","Res\\win2.bmp" ,"Res\\die.bmp" };

	for (int i = 0; i < RES_TYPE_PLAYER_END; i++)
	{
		m_pBitMapPlayer[i] = new BitMap();
		m_pBitMapPlayer[i]->Init(hdc, storagePathPlayer[i]);
	}

	string storagePathObject[RES_TYPE_OBJECT_END] = { "Res\\end.bmp","Res\\cash.bmp","Res\\front.bmp","Res\\front2.bmp","Res\\enemy_1b.bmp" ,"Res\\enemy_1f.bmp","Res\\enemy_b.bmp","Res\\enemy_f.bmp" };

	for (int i = 0; i < RES_TYPE_OBJECT_END; i++)
	{
		m_pBitMapObject[i] = new BitMap();
		m_pBitMapObject[i]->Init(hdc, storagePathObject[i]);
	}
}

BitMap* ResManager::GetBitMap(int index, RES_ENUM_TYPE num)
{
	//배열 검사
	if (num == RES_ENUM_TYPE::UI)
	{
		return m_pBitMapUi[index];
	}
	else if (num == RES_ENUM_TYPE::BACKGROUND)
	{
		return m_pBitMapBackground[index];
	}
	else if (num == RES_ENUM_TYPE::PLAYER)
	{
		return m_pBitMapPlayer[index];
	}
	else if (num == RES_ENUM_TYPE::OBJECT)
	{
		return m_pBitMapObject[index];
	}
}

void ResManager::Release()
{
	for (int i = 0; i < RES_TYPE_UI_END; i++)
	{
		SAFE_DELETE(m_pBitMapUi[i]);
	}

	for (int i = 0; i < RES_TYPE_BACKGROUND_END; i++)
	{
		SAFE_DELETE(m_pBitMapBackground[i]);
	}

	for (int i = 0; i < RES_TYPE_PLAYER_END; i++)
	{
		SAFE_DELETE(m_pBitMapPlayer[i]);
	}

	for (int i = 0; i < RES_TYPE_OBJECT_END; i++)
	{
		SAFE_DELETE(m_pBitMapObject[i]);
	}
}
