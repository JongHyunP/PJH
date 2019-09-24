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

bool ChessBishop::Init()
{
	return true;
}

void ChessBishop::Draw(HDC hdc)
{
	//m_pBitMap->Draw(hdc, m_iX, m_iY, false);
}

ChessBishop* ChessBishop::Clone()
{
	return new ChessBishop(*this);
}

void ChessBishop::SetBishopInfo(BitMap* pBitMap, int x, int y)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
}
