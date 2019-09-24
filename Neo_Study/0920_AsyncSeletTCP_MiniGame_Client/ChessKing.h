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
	virtual bool Init();
	virtual void Draw(HDC hdc);
	virtual	ChessKing* Clone();
public:
	void SetKingInfo(BitMap* pBitMap, int x, int y);
private:
	friend class ChessPieceManager;
};

