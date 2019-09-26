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

bool ChessRook::Init(BitMap* pBitMap, int iPosX, int iPosY, int iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_iColor = iColor;

	return true;
}

void ChessRook::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

bool ChessRook::Input(POINT pt)
{
	RECT rc = { m_iX ,m_iY,m_iX + CHESSPIECE_SIZE_X, m_iY + CHESSPIECE_SIZE_Y };

	if (PtInRect(&rc, pt))
	{
		cout << "�� ����" << endl;
		// ���� �޾Ҵ�.( ǥ�� )
		// �� ü������ �ൿ ���� ����
		return true;
	}

	return false;
}

void ChessRook::Move()
{

}
