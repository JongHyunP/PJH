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

public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY);
	virtual void Draw(HDC hdc);

private:
	friend class ChessPieceManager;
};

