#pragma once
#include "value.h"

class BoardTile;
class ResManager;


class MainGame
{
	DECLARE_SINGLE(MainGame)
private:
	ResManager* m_pResManager;
	BoardTile* m_pBoard[8][8];
	vector<BoardTile*> m_vecBoardTile;
	//Player* m_pPlayer;
	

public:
	
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Update();
	void Release();

	
};

