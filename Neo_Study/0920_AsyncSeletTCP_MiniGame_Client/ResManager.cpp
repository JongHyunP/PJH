#include "value.h"
#include "ResManager.h"
#include "BitMap.h"

DEFINITION_SINGLE(ResManager)

ResManager::ResManager()
{

}


ResManager::~ResManager()
{
}

void ResManager::InitBackBuffer(HDC hdc)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = CreateCompatibleBitmap(hdc, 800, 800);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);
}

HDC ResManager::GetBackBuffer()
{
	return m_hMemDC;
}

void ResManager::DrawScene(HDC hdc) //화면 마지막에 그려주는애
{//             어디에/ 비트맵 어디서/      /비트맵 어디까지
	BitBlt(hdc, 0, 0, 1200, 1200, m_hMemDC, 0, 0, SRCCOPY);
}


bool ResManager::Init(HDC hdc)
{
	InitBackBuffer(hdc);

	BitMap* pNewBit;

	string storagePathBoard[RES_TYPE_BOARD_END] = { "RES\\block_b_00.bmp","RES\\block_b_01.bmp","RES\\block_b_02.bmp","RES\\block_b_03.bmp","RES\\block_b_04.bmp","RES\\block_b_05.bmp",
													"RES\\block_w_00.bmp","RES\\block_w_01.bmp","RES\\block_w_02.bmp","RES\\block_w_03.bmp","RES\\block_w_04.bmp", "RES\\block_w_05.bmp",
													"RES\\block00.bmp" ,"RES\\block01.bmp" ,"RES\\block02.bmp" ,"RES\\block03.bmp","RES\\block04.bmp" };

	for (int i = 0; i < RES_TYPE_BOARD_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathBoard[i]);
		m_mapBitMap.insert(make_pair(storagePathBoard[i], pNewBit));
	}
	
	return true;
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
