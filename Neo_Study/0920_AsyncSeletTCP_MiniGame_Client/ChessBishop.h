#pragma once
#include "ChessPiece.h"
class ChessBishop :
	public ChessPiece
{
private:
	ChessBishop();
	~ChessBishop();
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

