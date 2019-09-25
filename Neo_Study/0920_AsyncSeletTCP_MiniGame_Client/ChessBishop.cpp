#include "ChessBishop.h"
#include "BitMap.h"

ChessBishop::ChessBishop()
{

}
ChessBishop::ChessBishop(const ChessBishop& chessPiece) : ChessPiece(chessPiece)
{
	
}
ChessBishop::~ChessBishop()
{
}

bool ChessBishop::Init(BitMap* pBitMap, int iPosX, int iPosY)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;

	return true;
}

void ChessBishop::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

