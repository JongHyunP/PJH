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

bool ChessPawn::Init()
{
	return true;
}

void ChessPawn::Draw(HDC hdc)
{
}

ChessPawn* ChessPawn::Clone()
{
	return new ChessPawn(*this);
}

void ChessPawn::SetPawnInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
