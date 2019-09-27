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

bool ChessKnight::Init(BitMap* pBitMap, int iPosX, int iPosY, PIECE_COLOR_TYPE eColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_eColor = eColor;
	m_eType = CT_KNIGHT;

	ChessPiece::SetPieceInfo(m_eType, m_eColor, m_iX, m_iY);
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
		cout << "����Ʈ ����" << endl;
		// ���� �޾Ҵ�.( ǥ�� )
		// �� ü������ �ൿ ���� ����
		return true;
	}

	return false;
}

void ChessKnight::Move()
{
}
