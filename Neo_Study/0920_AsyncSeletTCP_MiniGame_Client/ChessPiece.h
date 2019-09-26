#pragma once
#include "value.h"

#define CHESSPIECE_SIZE_X 100
#define CHESSPIECE_SIZE_Y 100

class BitMap;

class ChessPiece
{
protected:
	ChessPiece();
	ChessPiece(const ChessPiece& chessPiece);
public:	
	virtual ~ChessPiece();

public:
	virtual bool Init(BitMap* pBitMap,int iPosX, int iPosY,int id) = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual bool Input(POINT pt) = 0;
	virtual void Move() = 0;

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

