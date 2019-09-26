#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessRook :
	public ChessPiece
{
private:
	ChessRook(); 
	ChessRook(const ChessRook& chessPiece);
	virtual ~ChessRook();

private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	int m_iColor;

public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY, int iColor);
	virtual void Draw(HDC hdc);
	virtual bool Input(POINT pt);
	virtual void Move();
private:
	friend class ChessPieceManager;
};

