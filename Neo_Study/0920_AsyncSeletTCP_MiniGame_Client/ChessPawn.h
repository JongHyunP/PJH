#pragma once
#include "ChessPiece.h"
class ChessPawn :
	public ChessPiece
{
private:
	ChessPawn();
	~ChessPawn();
public:
	virtual bool Init();
	virtual void Draw(HDC hdc);
private:
	friend class ChessPieceManager;
};

