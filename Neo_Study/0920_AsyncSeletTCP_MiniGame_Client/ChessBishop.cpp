#include "ChessBishop.h"
#include "BitMap.h"
#include "ResManager.h"

ChessBishop::ChessBishop()
{

}

ChessBishop::~ChessBishop()
{

}

bool ChessBishop::Init()
{
	m_pResManager = new ResManager;
	m_pBitMap = m_pResManager->GetBitMap("RES\\block_b_02.bmp");
	m_iX = 0;
	m_iY = 0;
	
	return true;
}

void ChessBishop::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, false);
}
