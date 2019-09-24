#include "ChessRook.h"
#include "BitMap.h"

ChessRook::ChessRook()
{

}
ChessRook::ChessRook(const ChessRook& chessPiece) : ChessPiece(chessPiece)
{

}
ChessRook::~ChessRook()
{

}

bool ChessRook::Init()
{
	return true;
}

void ChessRook::Draw(HDC hdc)
{
}

ChessRook* ChessRook::Clone()
{
	return new ChessRook(*this);
}

void ChessRook::SetRookInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
