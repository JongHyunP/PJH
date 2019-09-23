#pragma once
#include "ChessPiece.h"
class ChessRook :
	public ChessPiece
{
private:
	ChessRook();
	~ChessRook();
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

