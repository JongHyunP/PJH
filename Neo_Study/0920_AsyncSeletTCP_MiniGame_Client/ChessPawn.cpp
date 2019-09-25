#include "ChessPawn.h"
#include "BitMap.h"

ChessPawn::ChessPawn()
{

}
ChessPawn::ChessPawn(const ChessPawn& chessPiece) : ChessPiece(chessPiece)
{

}
ChessPawn::~ChessPawn()
{

}

bool ChessPawn::Init(BitMap* pBitMap, int iPosX, int iPosY)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;

	return true;
}

void ChessPawn::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}