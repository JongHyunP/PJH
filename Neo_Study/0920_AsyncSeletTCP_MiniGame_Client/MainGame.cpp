#include "MainGame.h"
#include "ResManager.h"
#include "BoardTile.h"
#include "ChessPieceManager.h"

DEFINITION_SINGLE(MainGame)

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	DESTROY_SINGLE(ChessPieceManager);
}

bool MainGame::Init(HWND hWnd, HDC hdc)
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
			
			if (i % 2 == 0 && j% 2==0)
			{
				m_pBoard[j][i]->Init(m_pResManager->GetBitMap("RES\\block01.bmp"), x, y, 100, 100);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else if (i % 2 == 1 && j% 2 ==1)
			{
				m_pBoard[j][i]->Init(m_pResManager->GetBitMap("RES\\block01.bmp"), x, y, 100, 100);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else
			{
				m_pBoard[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 100, 100);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
		}
		x = 0;
		y += 100;
	}

	// 체스말 관리자 초기화.
	if (!GET_SINGLE(ChessPieceManager)->Init())
	{
		return false;
	}


	return true;
}

void MainGame::Draw(HDC hdc)
{
	for (auto iter = m_vecBoardTile.begin(); iter != m_vecBoardTile.end(); iter++)
	{
		(*iter)->Draw(m_pResManager->GetBackBuffer());
	}
	GET_SINGLE(ChessPieceManager)->Draw(hdc);
	m_pResManager->DrawScene(hdc);
}

void MainGame::Update()
{

}