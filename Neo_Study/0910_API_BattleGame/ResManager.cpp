#include "ResManager.h"
#include "mecro.h"
#include "BitMap.h"


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

void ResManager::DrawScene(HDC hdc) //화면 마지막에 그려주는애
{//             어디에/ 비트맵 어디서/      /비트맵 어디까지
	BitBlt(hdc, 0, 0, WIN_X, WIN_Y, m_hMemDC, 0, 0, SRCCOPY);
}

void ResManager::Init(HDC hdc)
{
	InitBackBuffer(hdc);
	BitMap* pNewBit;

	string storagePathETC[RES_TYPE_ETC_END] = { "RES\\BlackBack.bmp","RES\\GrayBack.bmp","RES\\missile_00.bmp","RES\\player_icon.bmp","RES\\enemy_icon.bmp","RES\\stage_icon.bmp" };

	for (int i = 0; i < RES_TYPE_ETC_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathETC[i]);
		m_mapBitMap.insert(make_pair(storagePathETC[i], pNewBit));
	}

	string storagePathPlayer[RES_TYPE_PLAYER_END] = { "RES\\tank_down_00.bmp","RES\\tank_down_01.bmp","RES\\tank_left_00.bmp","RES\\tank_left_01.bmp" ,"RES\\tank_right_00.bmp" ,"RES\\tank_right_01.bmp" ,"RES\\tank_up_00.bmp" ,"RES\\tank_up_01.bmp" ,"RES\\shield_00.bmp" ,"RES\\shield_01.bmp" };

	for (int i = 0; i < RES_TYPE_PLAYER_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathPlayer[i]);
		m_mapBitMap.insert(make_pair(storagePathPlayer[i], pNewBit));
	}

	string storagePathEnemy[RES_TYPE_ENEMY_END] = { "RES\\ENEMY_DOWN_01.bmp","RES\\ENEMY_DOWN_02.bmp","RES\\ENEMY_DOWN_03.bmp","RES\\ENEMY_LEFT_01.bmp" ,"RES\\ENEMY_LEFT_02.bmp" ,"RES\\ENEMY_LEFT_03.bmp" ,"RES\\ENEMY_RIGHT_01.bmp" ,"RES\\ENEMY_RIGHT_02.bmp" ,"RES\\ENEMY_RIGHT_03.bmp" ,"RES\\ENEMY_UP_01.bmp","RES\\ENEMY_UP_02.bmp","RES\\ENEMY_UP_03.bmp" };

	for (int i = 0; i < RES_TYPE_ENEMY_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathEnemy[i]);
		m_mapBitMap.insert(make_pair(storagePathEnemy[i], pNewBit));
	}

	string storagePathBlock[RES_TYPE_BLOCK_END] = { "RES\\block00.bmp","RES\\block01.bmp","RES\\block02.bmp","RES\\block03.bmp" ,"RES\\block04.bmp" ,"RES\\block05.bmp" ,"RES\\block06.bmp" ,"RES\\block07.bmp" ,"RES\\block08.bmp" ,"RES\\block09.bmp","RES\\block10.bmp","RES\\block11.bmp" ,"RES\\block12.bmp" ,"RES\\block13.bmp","RES\\block14.bmp" };

	for (int i = 0; i < RES_TYPE_BLOCK_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathBlock[i]);
		m_mapBitMap.insert(make_pair(storagePathBlock[i], pNewBit));
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
