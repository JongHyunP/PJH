#pragma once
#include "value.h"

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_ONE,
	GAME_STATE_SHOW
};

class Card;

class MainGame
{
	DECLARE_SINGLE(MainGame)

private:
	vector<Card*>	m_vecCard;
	HWND			m_hWnd;
	GAME_STATE		m_eState;
	Card*			m_pSelectOne;
	Card*			m_pSelectTwo;
	DWORD			m_dwCount;

public:

	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Input(POINT pt);
	void Update();
	void Release();

};

