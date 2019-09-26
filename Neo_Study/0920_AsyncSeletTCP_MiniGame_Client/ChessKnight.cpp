#include "ChessKnight.h"
#include "BitMap.h"

ChessKnight::ChessKnight()
{

}

ChessKnight::ChessKnight(const ChessKnight& chessPiece) : ChessPiece(chessPiece)
{

}

ChessKnight::~ChessKnight()
{

}

bool ChessKnight::Init(BitMap* pBitMap, int iPosX, int iPosY,int iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_iColor = iColor;
	return true;
}

void ChessKnight::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

bool ChessKnight::Input(POINT pt)
{
	RECT rc = { m_iX ,m_iY,m_iX + CHESSPIECE_SIZE_X, m_iY + CHESSPIECE_SIZE_Y };

	if (PtInRect(&rc, pt))
	{
		cout << "나이트 선택" << endl;
		// 선택 받았다.( 표시 )
		// 이 체스말의 행동 실행 가능
		return true;
	}

	return false;
}

void ChessKnight::Move()
{
}
