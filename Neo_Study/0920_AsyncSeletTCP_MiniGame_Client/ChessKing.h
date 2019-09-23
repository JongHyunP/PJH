#pragma once
#include "ChessPiece.h"
class ChessKing :
	public ChessPiece
{
private:
	ChessKing();
	~ChessKing();
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

