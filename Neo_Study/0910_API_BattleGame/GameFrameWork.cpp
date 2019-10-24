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

}

GameFrameWork::~GameFrameWork()
{
		
}

bool GameFrameWork::Init(HWND hWnd, HDC hdc)
{
	m_LastTime = std::chrono::system_clock::now();
	m_hWnd = hWnd;

	//리소스 관리자 초기화
	if (!GET_SINGLE(ResManager)->Init(hdc))
	{
		return false;
	}


	Player_x = 300.0f;
	Player_y = 300.0f;
	
	m_pPlayer = new Player();
	m_pPlayer->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\tank_up_00.bmp"), Player_x, Player_y, 25, 25);

	MapObjectSetting();

	return  true;
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

	DESTROY_SINGLE(ResManager);
	SAFE_DELETE(m_pPlayer);

}

void GameFrameWork::Animaition()
{
	// 플레이어의 이미지 애니메이션과 관련된 함수.

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
	std::chrono::duration<float> sec = std::chrono::system_clock::now() - m_LastTime;

	m_fElapseTime = sec.count();
	m_fFrameCount = sec.count();

	m_LastTime = std::chrono::system_clock::now();

	OperateInput();

	CollisionCheck();

	Render(hdc);
}

void GameFrameWork::CollisionCheck()
{
	/**
	*@code 충돌 관련 함수입니다. 오브젝트의 타입마다 충돌체인지 아닌지 판단해줍니다.
	*/
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
	/**
	*@endcode .
	*/
}

void GameFrameWork::OperateInput() //플레이어 조종
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		m_pPlayer->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\tank_left_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x > 0)
		{
			Player_x -= 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		m_pPlayer->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\tank_right_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_x < 500)
		{
			Player_x += 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_pPlayer->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\tank_up_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y > 0)
		{
			Player_y -= 100 * m_fElapseTime;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_pPlayer->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\tank_down_00.bmp"), Player_x, Player_y, 25, 25);
		if (Player_y < 375)
		{
			Player_y += 100 * m_fElapseTime;
		}
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		
	}

}

void GameFrameWork::MapObjectSetting()
{
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
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block13.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_13);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);

				}
				else if (i == 15 && j == 9)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 9)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 10)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 11)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 15 && j == 11)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 5 && j == 5)
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block06.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_06);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else
				{
					m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\BlackBack.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_15);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
			}
			else
			{
				m_pObject[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\GrayBack.bmp"), x, y, 25, 25, RES_TYPE_BLOCK::BLOCK_16);
				x += 25;
				m_vecFixedObject.push_back(m_pObject[j][i]);
			}
		}
		x = 0;
		y += 25;
	}
}

void GameFrameWork::Render(HDC hdc)
{
	//맵 오브젝트
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); iter++)
	{
		(*iter)->Draw(GET_SINGLE(ResManager)->GetBackBuffer(), true);
	}

	//플레이어 캐릭터
	m_pPlayer->Draw(GET_SINGLE(ResManager)->GetBackBuffer(), Player_x, Player_y);

	//플레이어 위에 덮는 풀
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); iter++)
	{
		if ((*iter)->GetObjectID() == BLOCK_06)
		{
			(*iter)->Draw(GET_SINGLE(ResManager)->GetBackBuffer(), true);
		}
	}

	//출력
	GET_SINGLE(ResManager)->DrawScene(hdc);
}
