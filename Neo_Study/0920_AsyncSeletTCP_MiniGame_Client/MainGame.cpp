#include "MainGame.h"
#include "ResManager.h"
#include "BoardTile.h"
#include "macro.h"

MainGame* MainGame::m_sThis = nullptr;

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init(HWND hWnd, HDC hdc)
{
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc);
	
	int x = 0;
	int y = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_pBoard[j][i] = new BoardTile();
			
			if (i % 2 == 0)
			{
				//m_pBoard[j][i]
			}
		}
	}
}