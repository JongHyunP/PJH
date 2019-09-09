#include "BackTile.h"
#include "BitMap.h"


BackTile::BackTile()
{
}


BackTile::~BackTile()
{
}

void BackTile::Init(BitMap* pBitMap, int x, int y, int cx, int cy)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
	m_iCX = cx;
	m_iCY = cy;
}

void BackTile::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY , false);
}

void BackTile::Update(int moveX)
{
	m_iX = m_iX + moveX;
}
