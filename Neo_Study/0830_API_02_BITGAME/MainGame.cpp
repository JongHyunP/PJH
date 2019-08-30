#include "MainGame.h"

MainGame* MainGame::sMainGame = nullptr;

MainGame::MainGame()
{

}


MainGame::~MainGame()
{
}

void MainGame::Init(HWND hWnd, HDC hdc)
{
	
}

void MainGame::Input(LPARAM lParam)
{

}

void MainGame::Draw(HDC hdc)
{

}

void MainGame::Relese()
{
	SAFE_DELETE(sMainGame);
}
