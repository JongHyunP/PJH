#pragma once
#include "value.h"

class ChessPiece;

class ChessPieceManager
{
	DECLARE_SINGLE(ChessPieceManager)

private:
	unordered_map<string, ChessPiece*> m_mapPiece;
public:
	bool Init(HDC hdc);
	ChessPiece* CreatePiece(const string& strkey, CHESSPIECE_TYPE ePieceType, PIECE_COLOR_TYPE eColorType, int x, int y);
	ChessPiece* FindPiece(const string& strkey);
	void Draw(HDC hdc);
};

