#include "ChessKing.h"
#include "BitMap.h"

ChessKing::ChessKing()
{

}
ChessKing::ChessKing(const ChessKing& chessPiece) : ChessPiece(chessPiece)
{

}
ChessKing::~ChessKing()
{

}

bool ChessKing::Init()
{
	return true;
}

void ChessKing::Draw(HDC hdc)
{

}

ChessKing* ChessKing::Clone()
{
	return new ChessKing(*this);
}

void ChessKing::SetKingInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
