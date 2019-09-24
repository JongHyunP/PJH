#pragma once
#include "value.h"

class ChessPiece;

class ChessPieceManager
{
	DECLARE_SINGLE(ChessPieceManager)

private:
	unordered_map<string, ChessPiece*> m_mapPiece;
public:
	bool Init();
	ChessPiece* CreatePiece(const string& strkey, CHESSPIECE_TYPE eType);
	ChessPiece* FindPiece(const string& strkey);
	void Draw(HDC hdc);
};

