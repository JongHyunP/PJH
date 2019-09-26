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

bool ChessKing::Init(BitMap* pBitMap, int iPosX, int iPosY, int iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_iColor = iColor;

	return true;
}

void ChessKing::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

bool ChessKing::Input(POINT pt)
{
	RECT rc = { m_iX ,m_iY,m_iX + CHESSPIECE_SIZE_X, m_iY + CHESSPIECE_SIZE_Y };

	if (PtInRect(&rc, pt))
	{
		cout << "ŷ ����" << endl;
		// ���� �޾Ҵ�.( ǥ�� )
		// �� ü������ �ൿ ���� ����
		return true;
	}

	return false;
}

void ChessKing::Move()
{
}

