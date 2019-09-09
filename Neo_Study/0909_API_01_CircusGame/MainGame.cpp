#include "MainGame.h"
#include "macro.h"
#include "BackTile.h"
#include "ResManager.h"
#include "Player.h"

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
	for (int i = 0; i < 40; i++) // 2680 타일작업
	{
		BackTile* pNew = new BackTile();
		pNew->Init(m_pResManager->GetBitMap("RES\\back.bmp"), i * 67, 380, 67, 183);
		m_vecTile.push_back(pNew);
	}

	int x = 0;

	for (int i = 0; i < 40; i++)
	{
		BackTile* pNew = new BackTile();
		if (i % 5 == 0) // 코끼리
		{
			pNew->Init(m_pResManager->GetBitMap("RES\\back_deco.bmp"), x, 307, 66, 67);
			x += 66;
		}
		else // 관중
		{
			pNew->Init(m_pResManager->GetBitMap("RES\\back_normal.bmp"), x, 310, 65, 64);
			x += 65;
		}
			
		m_vecTile.push_back(pNew);
	}

	m_pPlayer = new Player();
	m_pPlayer->Init(m_pResManager , 100, 495, 66, 63);
}

void MainGame::Draw(HDC hdc)
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		(*iter)->Draw(m_pResManager->GetBackBuffer());
	}

	m_pPlayer->Draw(m_pResManager->GetBackBuffer());

	m_pResManager->DrawScene(hdc);
}

void MainGame::Update()
{
	m_pPlayer->Update();
	
}

void MainGame::Input(int virtualKey, bool iskeydown)
{
	if (iskeydown)
	{
		switch (virtualKey)
		{
		case VK_RIGHT:
			m_pPlayer->Move(INPUT_RIGHT);
			for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
			{
				(*iter)->Update(-5);
			}
			break;
		case VK_LEFT:
			m_pPlayer->Move(INPUT_LEFT);
			for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
			{
				(*iter)->Update(+5);
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (virtualKey)
		{
		case VK_RIGHT:
			m_pPlayer->Move(INPUT_STOP);
			break;
		case VK_LEFT:
			m_pPlayer->Move(INPUT_STOP);
			break;
		default:
			break;
		}
	}
}

void MainGame::Release()
{
	m_pResManager->Release();

	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}
