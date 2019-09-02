#include "ResManager.h"
#include "BitMap.h"
#include "mecro.h"

ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}

void ResManager::Init(HDC hdc)
{
	string storagePath[RES_TYPE_END] = { "Res\\00.bmp", "Res\\01.bmp","Res\\02.bmp","Res\\03.bmp","Res\\04.bmp","Res\\05.bmp","Res\\06.bmp","Res\\07.bmp", "Res\\08bmp", "Res\\09.bmp", "Res\\10.bmp", "Res\\11.bmp", "Res\\12.bmp"};
	
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		m_pBitMap[i] = new BitMap();
		m_pBitMap[i]->Init(hdc, storagePath[i]);
	}
}

BitMap* ResManager::GetBitMap(int index)
{
	//배열 검사

	return m_pBitMap[index];
}

void ResManager::Release()
{
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		SAFE_DELETE(m_pBitMap[i]);
	}
}
