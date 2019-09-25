#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessBishop :
	public ChessPiece
{
private:
	ChessBishop();
	ChessBishop(const ChessBishop& chessPiece);
	virtual ~ChessBishop();

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

