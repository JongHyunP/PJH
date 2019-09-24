#pragma once
#include "value.h"

class ChessPiece
{
protected:
	ChessPiece();
	ChessPiece(const ChessPiece& chessPiece);
public:	
	virtual ~ChessPiece();

public:
	virtual bool Init() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual	ChessPiece* Clone() = 0;

protected:
	PIECEINFO m_tInfo;

public:
	void SetPieceInfo(CHESSPIECE_TYPE eChessType, PIECE_COLOR_TYPE ePieceColorType);

public:
	PIECEINFO GetPieceInfo() const
	{
		return m_tInfo;
	}

private:
	friend class ChessPieceManager;
};

