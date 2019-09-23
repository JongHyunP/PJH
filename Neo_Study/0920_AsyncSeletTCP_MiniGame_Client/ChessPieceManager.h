#pragma once
#include "value.h"

class ResManager;

class ChessPieceManager
{
private:
	unordered_map<string, class ChessPiece*> m_mapPiece;
public:
	ResManager* m_pResManager;
	bool Init();
	ChessPiece* CreatePiece(const string& strkey, CHESSPIECE_TYPE eType);
	ChessPiece* FindPiece(const string& strkey);
	void Draw(HDC hdc);

	DECLARE_SINGLE(ChessPieceManager);
};

