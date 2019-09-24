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

void ChessPiece::SetPieceInfo(CHESSPIECE_TYPE eChessType, PIECE_COLOR_TYPE ePieceColorType)
{
	m_tInfo.eChessType = eChessType;
	m_tInfo.ePieceColorType = ePieceColorType;
}