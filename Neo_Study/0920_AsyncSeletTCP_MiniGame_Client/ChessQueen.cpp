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

bool ChessQueen::Init(BitMap* pBitMap, int iPosX, int iPosY, int iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_iColor = iColor;

	return true;
}

void ChessQueen::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}


bool ChessQueen::Input(POINT pt)
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

void ChessQueen::Move()
{
}
