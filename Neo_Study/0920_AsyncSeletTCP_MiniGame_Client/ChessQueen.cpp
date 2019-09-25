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

bool ChessQueen::Init(BitMap* pBitMap, int iPosX, int iPosY)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;

	return true;
}

void ChessQueen::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}