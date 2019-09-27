#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessKnight :
	public ChessPiece
{
private:
	ChessKnight();
	ChessKnight(const ChessKnight& chessPiece);
	virtual ~ChessKnight();
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	PIECE_COLOR_TYPE m_eColor;
	CHESSPIECE_TYPE m_eType;
public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY, PIECE_COLOR_TYPE eColor);
	virtual void Draw(HDC hdc);
	virtual	bool Input(POINT pt);
	virtual void Move();

private:
	friend class ChessPieceManager;
};

