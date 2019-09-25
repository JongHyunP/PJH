#pragma once
#include "value.h"

class BitMap;

class ChessPiece
{
protected:
	ChessPiece();
	ChessPiece(const ChessPiece& chessPiece);
public:	
	virtual ~ChessPiece();

public:
	virtual bool Init(BitMap* pBitMap,int iPosX, int iPosY) = 0;
	virtual void Draw(HDC hdc) = 0;

protected:
	PIECEINFO m_tInfo;

public:
	PIECEINFO GetPieceInfo() const
	{
		return m_tInfo;
	}

private:
	friend class ChessPieceManager;
};

