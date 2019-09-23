#pragma once
#include "ChessPiece.h"
class ChessQueen :
	public ChessPiece
{
private:
	ChessQueen();
	~ChessQueen();
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

