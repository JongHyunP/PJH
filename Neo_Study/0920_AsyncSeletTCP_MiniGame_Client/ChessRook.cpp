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

bool ChessRook::Init(BitMap* pBitMap, int iPosX, int iPosY)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;

	return true;
}

void ChessRook::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}