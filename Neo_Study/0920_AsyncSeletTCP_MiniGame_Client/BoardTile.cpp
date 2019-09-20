#include "BoardTile.h"
#include "BitMap.h"


BoardTile::BoardTile()
{
}


BoardTile::~BoardTile()
{
}


void BoardTile::Init(BitMap * pBitMap, int x, int y, int cx, int cy)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
	m_iCX = cx;
	m_iCY = cy;
}

void BoardTile::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX , m_iY, false);
}