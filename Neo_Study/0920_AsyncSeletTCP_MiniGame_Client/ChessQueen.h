#pragma once
#include "ChessPiece.h"
class ChessQueen :
	public ChessPiece
{
public:
	virtual bool Init(BitMap* pBitMap, int x, int y, int cx, int cy);
	virtual void Draw(HDC hdc);
};

