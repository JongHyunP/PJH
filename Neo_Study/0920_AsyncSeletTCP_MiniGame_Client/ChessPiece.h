#pragma once
#include "value.h"

class BitMap;

class ChessPiece
{
public:
	ChessPiece();
	virtual ~ChessPiece();

public:
	virtual bool Init(BitMap* pBitMap, int x, int y, int cx, int cy) = 0;
	virtual void Draw(HDC hdc) = 0;
};

