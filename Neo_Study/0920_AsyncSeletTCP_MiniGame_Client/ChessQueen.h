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
	virtual bool Init();
	virtual void Draw(HDC hdc);
	virtual	ChessQueen* Clone();
public:
	void SetQueenInfo(BitMap* pBitMap, int x, int y);
private:
	friend class ChessPieceManager;
};

