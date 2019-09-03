#include "GameManager.h"
#include "mecro.h"
#include "ResManager.h"
#include "Mine.h"
#include "MineMap.h"

GameManager* GameManager::m_sThis = nullptr;


GameManager::GameManager()
{
	m_eState = GAME_STATE_WAIT;
	m_pResManager = nullptr;
	m_pSelectMine = nullptr;
	m_pSelectMineMap = nullptr;
	m_level = MAP_LEVEL::LEVEL_EASY;
	m_dwTimeCount = 0;
	m_iCount = 0;
}

void GameManager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_hWnd = hWnd;
	srand(GetTickCount());

	m_pResManager = new ResManager();
	m_pResManager->Init(hdc);

	// 랜덤 지뢰를 어떻게 깔고 그 주변 블럭 넘버 박아주는 작업 해야함.
	MineRandomArray = new int[100];
	int mineNum = 5;
	int mineRandomX[5];
	
	for (int i = 0; i < 100; i++)
	{
		MineRandomArray[i] = 2;
	}

	for (int i = 0; i < 5; i++)
	{
		mineRandomX[i] = rand() % 100;

		for (int j = 0; j <= i; j++) //현재 발생시킨 지점까지 검색해서 같은수 비교
		{
			if (mineRandomX[i] == mineRandomX[j] && j != i)
			{
				i = i - 1; // 같은수 있으면 i하나 감소해서 다시 발생
			}
		}
		MineRandomArray[mineRandomX[i]] = 12;
	}

	for (int i = 0; i < 100; i++)
	{
		if (MineRandomArray[i - 11])
		{
			if (MineRandomArray[i - 11] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i - 10])
		{
			if (MineRandomArray[i - 10] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i - 9])
		{
			if (MineRandomArray[i - 9] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i - 1])
		{
			if (MineRandomArray[i - 1] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i + 1])
		{
			if (MineRandomArray[i + 1] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i + 9])
		{
			if (MineRandomArray[i + 9] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i + 10])
		{
			if (MineRandomArray[i + 10] == 12)
			{
				MineRandomArray[i]++;
			}
		}
		if (MineRandomArray[i + 11])
		{
			if (MineRandomArray[i + 11] == 12)
			{
				MineRandomArray[i]++;
			}
		}
	}


	for (int i = 0; i < 100; i++)
	{
		Mine* pNew = new Mine();
		pNew->Init(m_pResManager->GetBitMap(MineRandomArray[i]), m_pResManager->GetBitMap(RES_TYPE_BLOCK),
			45+(i % 10)*SQUARE_LENGTH + 20 * (i % 10), 45+(i / 10)*SQUARE_LENGTH + 20 * (i / 10), MineRandomArray[i]);
		m_vecMine.push_back(pNew);
	}

	MineMap* pMapNew = new MineMap();
	pMapNew->Init(m_pResManager->GetBitMap(RES_TYPE_BACKGROUND), m_pResManager->GetBitMap(RES_TYPE_NONE), 0, 0, m_level, 400, 10, m_level);
	m_vecMineMap.push_back(pMapNew);
}

void GameManager::Draw(HDC hdc)
{
	m_vecMineMap[LEVEL_EASY]->Draw(hdc);

	for (auto iter = m_vecMine.begin(); iter != m_vecMine.end(); ++iter)
	{
		(*iter)->Draw(hdc);
	}
	//OptionMapDraw(hdc);
}

void GameManager::Update()
{
	if (m_eState == GAME_STATE_OVER)
	{
		return;
	}
	m_dwTimeCount++;

	if (m_dwTimeCount == 100)
	{

		m_pSelectMine = nullptr;
		m_eState = GAME_STATE_WAIT;
		m_dwTimeCount = 0;
		InvalidateRect(m_hWnd, NULL, false);
	}

}

void GameManager::InputLeftButton(POINT pt)
{
	if (m_eState == GAME_STATE_OVER)
	{
		return;
	}

	// 찾는 로직
	for (auto iter = m_vecMine.begin(); iter != m_vecMine.end(); ++iter) //지회벡터 순회
	{

		if ((*iter)->Input(pt)) //
		{
			if (m_eState == GAME_STATE_WAIT)
			{
				m_pSelectMine = *iter;

				if (m_pSelectMine->GetID() == 12)
				{
					m_eState = GAME_STATE_OVER;
				}
				else if (m_pSelectMine->GetID() == 2)
				{
					
				}
			}
			else if (m_eState == GAME_STATE_OVER)
			{
				//지뢰터짐
			}
			
			InvalidateRect(m_hWnd, NULL, false);
		}
	
	}
}


void GameManager::InputRightButton(POINT pt)
{
	if (m_eState == GAME_STATE_OVER)
	{
		return;
	}

}

void GameManager::OptionMapDraw(HDC hdc)
{
	if (m_level == LEVEL_EASY)
	{
		m_vecMineMap[LEVEL_EASY]->Draw(hdc);
	}
	else if (m_level == LEVEL_NOMAL)
	{
		m_vecMineMap[LEVEL_NOMAL]->Draw(hdc);
	}
	else if (m_level == LEVEL_HARD)
	{
		m_vecMineMap[LEVEL_HARD]->Draw(hdc);
	}
}

void GameManager::FindMineNeighborhood(int count, int vectorCount)
{

	if (m_vecMine[vectorCount - 1]->GetID() == 2)
	{
		m_vecMine[vectorCount - 1]->SetOpen();
	}

}


void GameManager::Release()
{
	for (auto iter = m_vecMine.begin(); iter != m_vecMine.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecMine.clear();

	for (auto iter = m_vecMineMap.begin(); iter != m_vecMineMap.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecMineMap.clear();


	m_pResManager->Release();
	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}


GameManager::~GameManager()
{

}
