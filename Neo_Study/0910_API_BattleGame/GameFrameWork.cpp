#include "GameFrameWork.h"
#include "ResManager.h"
#include "Object.h"
#include "Player.h"
#include "mecro.h"
#include <math.h>
#include <stdio.h>

GameFrameWork::GameFrameWork()
{
	//Player_x = 200.0f;
	//Player_y = 500.0f;

	//m_bJump = false;

	//m_fVectorX = 1.0f;
	//m_fVectorY = 0.0f; 플롯트 타입
}

GameFrameWork::~GameFrameWork()
{

}

void GameFrameWork::Init(HWND hWnd, HDC hdc)
{
	m_LastTime = std::chrono::system_clock::now();
	m_hWnd = hWnd;
	m_bIsCrush = false;
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc);
	Player_x = 300.0f;
	Player_y = 300.0f;
	
	m_pPlayer = new Player();
	m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_up_00.bmp"), Player_x, Player_y, 25, 25);

	int x = 0;
	int y = 0;
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			m_pObject[j][i] = new Object();

			if (i <= 15 && j <= 20)
			{
				if (i == 15 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block13.bmp"), x, y, 25, 25,BLOCK_13);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);

				}
				else if (i == 15 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 15 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\BlackBack.bmp"), x, y, 25, 25, BLACK_BACKGROUND);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
			}
			else
			{
				m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\GrayBack.bmp"), x, y, 25, 25, GRAY_BACKGROUND);
				x += 25;
				m_vecFixedObject.push_back(m_pObject[j][i]);
			}
		}
		x = 0;
		y += 25;
	}
}


void GameFrameWork::Release()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			delete m_pObject[j][i];
		}
	}
	m_pResManager->Release();

	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pResManager);
}

#define PI 3.141592f

void GameFrameWork::Update(HDC hdc)
{

	if (GetKeyState(VK_LBUTTON) & 0x8000) //호출 시점에서 눌린상태
	{
		POINT pt;
		GetCursorPos(&pt);

		ScreenToClient(m_hWnd, &pt);
	}

	std::chrono::duration<float> sec = std::chrono::system_clock::now() - m_LastTime;
	/*if (sec.count() < (1 / FPS))
		return;*/

	m_fElapseTime = sec.count();
	m_LastTime = std::chrono::system_clock::now();

	OperateInput();
	CollisionCheck(&(m_pPlayer->GetPlayerRect()),);
	Render(hdc);
}
void GameFrameWork::CollisionCheck(RECT* playerRect, RECT* objRect)
{
	RECT rcTemp;

	if (IntersectRect(&rcTemp,playerRect, objRect))
	{

	}
}
void GameFrameWork::OperateInput() //플레이어 조종
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_left_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x > 0)
		{
			Player_x -= 300 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_right_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x < 500)
		{
			Player_x += 300 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_up_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y > 0)
		{
			Player_y -= 300 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_down_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y < 375)
		{
			Player_y += 300 * m_fElapseTime;
		}
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		// 총알 쿨타임
		if (m_bJump == false) //플레이어 스테이트
		{
			// 키 다운
			m_bJump = true;

		}
		else
		{
			//누르고 있을때
		}
	}
	else
	{
		if (m_bJump)
		{
			//키 업
		}
		m_bJump = false;

	}

}

void GameFrameWork::Render(HDC hdc)
{
	//맵 오브젝트
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); iter++)
	{
		(*iter)->Draw(m_pResManager->GetBackBuffer(), true);
	}

	//플레이어 캐릭터
	m_pPlayer->Draw(m_pResManager->GetBackBuffer(), Player_x, Player_y);

	//출력
	m_pResManager->DrawScene(hdc);
}
