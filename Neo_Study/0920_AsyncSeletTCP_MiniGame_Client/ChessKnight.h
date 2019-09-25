#pragma once
#include "ChessPiece.h"

class BitMap;

class ChessKnight :
	public ChessPiece
{
private:
	ChessKnight();
	ChessKnight(const ChessKnight& chessPiece);
	virtual ~ChessKnight();
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	
public:
	virtual bool Init(BitMap* pBitMap, int iPosX, int iPosY);
	virtual void Draw(HDC hdc);
	//virtual	ChessKnight* Clone();

private:
	friend class ChessPieceManager;
};

