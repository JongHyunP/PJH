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

bool ChessBishop::Init(BitMap* pBitMap, int iPosX, int iPosY, PIECE_COLOR_TYPE iColor)
{
	m_pBitMap = pBitMap;
	m_iX = iPosX;
	m_iY = iPosY;
	m_eColor = iColor;
	m_eType = CT_BISHOP;

	ChessPiece::SetPieceInfo(m_eType, m_eColor, m_iX, m_iY);

	return true;
}

void ChessBishop::Draw(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, true);
}

bool ChessBishop::Input(POINT pt)
{
	RECT rc = { m_iX ,m_iY,m_iX + CHESSPIECE_SIZE_X, m_iY + CHESSPIECE_SIZE_Y };

	if (PtInRect(&rc, pt))
	{
		cout << "�����" << endl;
		// ���� �޾Ҵ�.( ǥ�� )
		// �� ü������ �ൿ ���� ����
		return true;
	}

	return false;
}

void ChessBishop::Move()
{
}

