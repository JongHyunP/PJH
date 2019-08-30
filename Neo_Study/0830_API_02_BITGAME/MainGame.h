#pragma once
#include <Windows.h>
#include "mecro.h"
class MainGame
{
private:
	static MainGame* sMainGame;
	
	MainGame();

public:
	~MainGame();
	static MainGame* getInstance()
	{
		if (sMainGame == nullptr)
		{
			sMainGame = new MainGame();
		}
		return sMainGame;
	}

	void Init(HWND hWnd, HDC hdc);
	void Input(LPARAM lParam);
	void Draw(HDC hdc);
	void Relese();
};

