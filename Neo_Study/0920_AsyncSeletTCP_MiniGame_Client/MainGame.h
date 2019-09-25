#pragma once
#include "value.h"

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_ONE_SELECT,
	GAME_STATE_MOVE
};

class BoardTile;

class MainGame
{
	DECLARE_SINGLE(MainGame)
private:
	
	BoardTile*			m_pBoard[8][8];
	vector<BoardTile*>	m_vecBoardTile;
	GAME_STATE			m_eState;
	//Player* m_pPlayer;
	

public:
	
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Input(POINT pt);
	void Update();
	void Release();

	
};

