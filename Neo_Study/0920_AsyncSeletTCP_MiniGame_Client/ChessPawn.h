#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessPawn :
	public ChessPiece
{
private:
	ChessPawn();
	ChessPawn(const ChessPawn& chessPiece);
	virtual~ChessPawn();

private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;

public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
	virtual	ChessPawn* Clone();

public:
	void SetPawnInfo(BitMap* pBitMap, int x, int y);

private:
	friend class ChessPieceManager;
};

