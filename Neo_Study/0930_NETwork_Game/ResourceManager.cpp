#include "ResourceManager.h"
#include "BitMap.h"

DEFINITION_SINGLE(ResourceManager)

ResourceManager::ResourceManager()
{

}


ResourceManager::~ResourceManager()
{

}

void ResourceManager::InitBackBuffer(HDC hdc)
{
	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = CreateCompatibleBitmap(hdc, 1600, 800);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);
}

HDC ResourceManager::GetBackBuffer()
{
	return m_hMemDC;
}

void ResourceManager::DrawScene(HDC hdc) //화면 마지막에 그려주는애
{//             어디에/ 비트맵 어디서/      /비트맵 어디까지
	BitBlt(hdc, 0, 0, 1600, 800, m_hMemDC, 0, 0, SRCCOPY);
}


bool ResourceManager::Init(HDC hdc)
{
	InitBackBuffer(hdc);

	BitMap* pNewBit;

	string storagePathCard[RES_TYPE_END] = { "RES\\00.bmp","RES\\01.bmp","RES\\02.bmp","RES\\03.bmp","RES\\04.bmp","RES\\05.bmp",
													"RES\\06.bmp","RES\\07.bmp","RES\\08.bmp","RES\\09.bmp","RES\\back.bmp" };

	for (int i = 0; i < RES_TYPE_END; i++)
	{
		pNewBit = new BitMap();
		pNewBit->Init(hdc, storagePathCard[i]);
		m_mapBitMap.insert(make_pair(storagePathCard[i], pNewBit));
	}

	return true;
}

BitMap* ResourceManager::GetBitMap(string strFileName)
{
	return m_mapBitMap[strFileName];
}

void ResourceManager::Release()
{
	for (auto iter = m_mapBitMap.begin(); iter != m_mapBitMap.end(); ++iter)
	{
		SAFE_DELETE((*iter).second);
	}
}