#include "ChessPawn.h"
#include "BitMap.h"

ChessPawn::ChessPawn()
{

}
ChessPawn::ChessPawn(const ChessPawn& chessPiece) : ChessPiece(chessPiece)
{

}
ChessPawn::~ChessPawn()
{

}

bool ChessPawn::Init(BitMap* pBitMap, int iPosX, int iPosY, PIECE_COLOR_TYPE iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_eColor = iColor;
	m_eType = CT_PAWN;

	ChessPiece::SetPieceInfo(m_eType, m_eColor, m_iX, m_iY);

	return true;
}

void ChessPawn::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}


bool ChessPawn::Input(POINT pt)
{
	RECT rc = { m_iX ,m_iY,m_iX + CHESSPIECE_SIZE_X, m_iY + CHESSPIECE_SIZE_Y };

	if (PtInRect(&rc, pt))
	{
		cout << "폰 선택" << endl;
		// 선택 받았다.( 표시 )
		// 이 체스말의 행동 실행 가능
		return true;
	}

	return false;
}

void ChessPawn::Move()
{
	if (m_eColor == PIECE_COLOR_WHITE)
	{
		m_iY -= 100;
	}
	else if (m_eColor == PIECE_COLOR_BLACK)
	{
		m_iY += 100;
	}
}
