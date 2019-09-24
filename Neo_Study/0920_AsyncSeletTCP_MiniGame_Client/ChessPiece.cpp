#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(const ChessPiece & chessPiece)
{
	m_strName = chessPiece.m_strName;
	m_ePieceType = chessPiece.m_ePieceType;
	m_eColorType = chessPiece.m_eColorType;
}

ChessPiece::~ChessPiece()
{

}

CHESSPIECE_TYPE ChessPiece::GetPieceType() const
{
	return m_ePieceType;
}

COLOR_TYPE ChessPiece::GetColorType() const
{
	return m_eColorType;
}
