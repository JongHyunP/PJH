#include "BoardTile.h"
#include "BitMap.h"


BoardTile::BoardTile()
{
}


BoardTile::~BoardTile()
{
}


void BoardTile::Init(BitMap * pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}

void BoardTile::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX , m_iY, false);
}