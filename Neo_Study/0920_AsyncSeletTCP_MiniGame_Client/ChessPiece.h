#pragma once
#include "value.h"

enum COLOR_TYPE
{
	BLACK_PIECE,
	WHITE_PIECE
};

class BitMap;

class ChessPiece
{
protected:
	ChessPiece();
	ChessPiece(const ChessPiece& chessPiece);
	virtual ~ChessPiece();

public:
	virtual bool Init() = 0;
	virtual void Draw(HDC hdc) = 0;

protected:
	string			m_strName;
	CHESSPIECE_TYPE m_ePieceType;
	COLOR_TYPE		m_eColorType;

public:
	CHESSPIECE_TYPE GetPieceType() const;
	COLOR_TYPE		GetColorType() const;

	void SetName(char* pName)
	{
		m_strName = pName;
	}
private:
	friend class ChessPieceManager;
	friend class ResManager;
};

