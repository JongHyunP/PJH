#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessKing :
	public ChessPiece
{
private:
	ChessKing();
	ChessKing(const ChessKing& chessPiece);
	virtual ~ChessKing();
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	PIECE_COLOR_TYPE m_eColor;
	CHESSPIECE_TYPE m_eType;

public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY, PIECE_COLOR_TYPE eColor);
	virtual void Draw(HDC hdc);
	virtual bool Input(POINT pt);
	virtual void Move();

private:
	friend class ChessPieceManager;
};

