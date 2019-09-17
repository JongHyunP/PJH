#include "GameFrameWork.h"
#include "ResManager.h"
#include "Object.h"
#include "Player.h"
#include "mecro.h"
#include <math.h>
#include <iostream>
#include <fstream>

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
	for (int i = 0; i < MAP_HIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			m_pObject[j][i] = new Object();

			if (i <= 15 && j <= 20)
			{
				if (i == 15 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block13.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_13);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);

				}
				else if (i == 15 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 15 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 5 && j == 5)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block06.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_06);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\BlackBack.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_15);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
			}
			else
			{
				m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\GrayBack.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_16);
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
	for (int i = 0; i < MAP_HIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			delete m_pObject[j][i];
		}
	}
	m_pResManager->Release();

	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pResManager);
}

#define PI 3.141592f

void GameFrameWork::Animaition()
{
	if (m_fElapseTime == 2)
	{
		m_fFrameCount = 0;
		m_fFrame++;

		if (m_fFrame >= 2)
		{
			m_fFrame = 0;
		}
	}
	
}

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
	m_fFrameCount = sec.count();

	m_LastTime = std::chrono::system_clock::now();

	OperateInput();

	CollisionCheck();

	Render(hdc);
}

void GameFrameWork::CollisionCheck()
{
	RECT rcTemp;
	RECT rcPlayer = { Player_x,Player_y,Player_x + 24,Player_y + 24 };

	for (int i = 0; i < MAP_HIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (IntersectRect(&rcTemp, &rcPlayer, &m_pObject[i][j]->GetObjectRect()))
			{
				SetRect(&rcTemp, 0, 0, rcTemp.right - rcTemp.left, rcTemp.bottom - rcTemp.top);

				if (m_pObject[i][j]->GetObjectID() == RES_TYPE_BLOCK::BLOCK_05 || m_pObject[i][j]->GetObjectID() == RES_TYPE_BLOCK::BLOCK_06 || m_pObject[i][j]->GetObjectID() == RES_TYPE_BLOCK::BLOCK_15)
				{
					
				}
				else
				{
					//위 아래 충돌
					if (rcTemp.right > rcTemp.bottom)
					{
						if ((rcPlayer.bottom + rcPlayer.top) / 2 < (m_pObject[i][j]->GetObjectRect().bottom + m_pObject[i][j]->GetObjectRect().top) / 2)
							Player_y -= rcTemp.bottom;
						else
							Player_y += rcTemp.bottom;
					}
					//오른쪽 왼쪽 충돌
					else
					{
						if ((rcPlayer.right + rcPlayer.left) / 2 < (m_pObject[i][j]->GetObjectRect().right + m_pObject[i][j]->GetObjectRect().left) / 2)
							Player_x -= rcTemp.right;
						else
							Player_x += rcTemp.right;
					}
				}
			}
		}
	}
}
void GameFrameWork::OperateInput() //플레이어 조종
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_left_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x > 0)
		{
			Player_x -= 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_right_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x < 500)
		{
			Player_x += 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_up_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y > 0)
		{
			Player_y -= 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_pPlayer->Init(m_pResManager->GetBitMap("RES\\tank_down_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y < 375)
		{
			Player_y += 100 * m_fElapseTime;
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

	//플레이어 위에 덮는 풀
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); iter++)
	{
		if ((*iter)->GetObjectID() == BLOCK_06)
		{
			(*iter)->Draw(m_pResManager->GetBackBuffer(), true);
		}
	}

	//출력
	m_pResManager->DrawScene(hdc);
}
