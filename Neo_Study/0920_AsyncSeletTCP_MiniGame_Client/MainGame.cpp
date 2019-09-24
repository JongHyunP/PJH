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
	DESTROY_SINGLE(ResManager);
}

bool MainGame::Init(HWND hWnd, HDC hdc)
{
	if (!GET_SINGLE(ResManager)->Init(hdc))
	{
		return false;
	}
	
	int x = 0;
	int y = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_pBoard[j][i] = new BoardTile();
			
			if (i % 2 == 0 && j% 2==0)
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block01.bmp"), x, y);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else if (i % 2 == 1 && j% 2 ==1)
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block01.bmp"), x, y);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y);
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
		(*iter)->Draw(GET_SINGLE(ResManager)->GetBackBuffer());
	}

	GET_SINGLE(ChessPieceManager)->Draw(hdc);

	GET_SINGLE(ResManager)->DrawScene(hdc);
}

void MainGame::Update()
{

}