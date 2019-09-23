#pragma once
#include "ChessPiece.h"
class ChessKnight :
	public ChessPiece
{
private:
	ChessKnight();
    ~ChessKnight();
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

