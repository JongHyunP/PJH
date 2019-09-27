#include "ChessPiece.h"
#include "ResManager.h"

ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(const ChessPiece & chessPiece)
{

}

ChessPiece::~ChessPiece()
{

}

bool ChessPiece::Input(POINT pt)
{
	return false;
}

void ChessPiece::SetPieceInfo(CHESSPIECE_TYPE ChessType, PIECE_COLOR_TYPE ColorType, int x, int y)
{
	m_tInfo.eChessType = ChessType;
	m_tInfo.ePieceColorType = ColorType;
	m_tInfo.iPosX = x;
	m_tInfo.iPosY = y;
}
