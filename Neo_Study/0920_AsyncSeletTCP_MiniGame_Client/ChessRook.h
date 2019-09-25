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

public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY);
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

