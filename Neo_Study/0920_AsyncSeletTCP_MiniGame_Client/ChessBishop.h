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
	virtual bool Init();
	virtual void Draw(HDC hdc);
	virtual	ChessBishop* Clone();

public:
	void SetBishopInfo(BitMap* pBitMap, int x, int y);
private:
	friend class ChessPieceManager;
};

