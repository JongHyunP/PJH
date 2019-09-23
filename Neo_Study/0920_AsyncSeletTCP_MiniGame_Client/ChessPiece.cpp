#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(const ChessPiece & chessPiece)
{
	//얕은복사 : 값복사
	//깊은 복사 : 참조로 하는 주소도 메모리공간을 할당하여 얕은복사시 일어날수있는 문제를
	//			 막을수있다.
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
