#include "ChessQueen.h"
#include "BitMap.h"

ChessQueen::ChessQueen()
{

}
ChessQueen::ChessQueen(const ChessQueen& chessPiece) : ChessPiece(chessPiece)
{

}

ChessQueen::~ChessQueen()
{

}

bool ChessQueen::Init()
{
	return true;
}

void ChessQueen::Draw(HDC hdc)
{
}

ChessQueen* ChessQueen::Clone()
{
	return new ChessQueen(*this);
}

void ChessQueen::SetQueenInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
