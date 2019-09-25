#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessQueen :
	public ChessPiece
{
private:
	ChessQueen();
	ChessQueen(const ChessQueen& chessPiece);
	virtual ~ChessQueen();

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

