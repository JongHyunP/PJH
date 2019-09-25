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

bool ChessKing::Init(BitMap* pBitMap, int iPosX, int iPosY)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	return true;
}

void ChessKing::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

//ChessKing* ChessKing::Clone()
//{
//	return new ChessKing(*this);
//}