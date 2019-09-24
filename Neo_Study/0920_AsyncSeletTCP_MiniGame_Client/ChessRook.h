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
	virtual bool Init();
	virtual void Draw(HDC hdc);
	virtual	ChessRook* Clone();

public:
	void SetRookInfo(BitMap* pBitMap, int x, int y);

private:
	friend class ChessPieceManager;
};

