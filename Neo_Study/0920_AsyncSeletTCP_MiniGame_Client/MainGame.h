#pragma once
#include "value.h"

class BoardTile;

class MainGame
{
	DECLARE_SINGLE(MainGame)
private:
	//Player* m_pPlayer;
	

public:
	
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Input(POINT pt);
	void Update();
	void Release();

	
};

