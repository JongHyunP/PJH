#include "GameManager.h"
#include "mecro.h"
#include "ResManager.h"
#include "Mine.h"
#include "MineMap.h"

GameManager* GameManager::m_sThis = nullptr;

GameManager::GameManager()
{
	m_pResManager = nullptr;
	m_pSelectMine = nullptr;
	m_pSelectMineMap = nullptr;
	m_level = MAP_LEVEL::LEVEL_EASY;
}

void GameManager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_hWnd = hWnd;
	//srand(GetTickCount());

	m_pResManager = new ResManager();
	m_pResManager->Init(hdc);

	// 랜덤 지뢰를 어떻게 깔고 그 주변 블럭 넘버 박아주는 작업 해야함.
	int MineRandomArray[527];
	
	for (int i = 0; i < 527; i++)
	{
		MineRandomArray[i] = 0;
	}

	for (int i = 0; i < 527; i++)
	{
		Mine* pNew = new Mine();
		pNew->Init(m_pResManager->GetBitMap(MineRandomArray[i]), m_pResManager->GetBitMap(RES_TYPE_BLOCK),
			45+(i % 31)*SQUARE_LENGTH + 20 * (i % 31), 45+(i / 31)*SQUARE_LENGTH + 20 * (i / 31), MineRandomArray[i]);
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
}

void GameManager::Input(POINT pt)
{
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
