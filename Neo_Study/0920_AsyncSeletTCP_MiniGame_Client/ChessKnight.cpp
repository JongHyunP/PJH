#include "ChessKnight.h"
#include "BitMap.h"

ChessKnight::ChessKnight()
{

}

ChessKnight::ChessKnight(const ChessKnight& chessPiece) : ChessPiece(chessPiece)
{

}

ChessKnight::~ChessKnight()
{

}

bool ChessKnight::Init()
{
	return true;
}

void ChessKnight::Draw(HDC hdc)
{
}

ChessKnight* ChessKnight::Clone()
{
	return new ChessKnight(*this);
}

void ChessKnight::SetKnightInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
