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
}

void GameManager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_level = MAP_LEVEL::LEVEL_EASY;
	m_hWnd = hWnd;
	srand(GetTickCount());
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc, hInst);

	// 랜덤 지뢰를 어떻게 깔고 그 주변 블럭 넘버 박아주는 작업 해야함.
	int MineRandomArray[100];
	
	for (int i = 0; i < 100; i++)
	{
		MineRandomArray[i] = i % 10;
	}

	for (int i = 0; i < 100; i++)
	{
		Mine* pNew = new Mine();
		pNew->Init(m_pResManager->GetBitMap(MineRandomArray[i]), m_pResManager->GetBitMap(RES_TYPE_BLOCK),
			10+(i % 10)*SQUARE_LENGTH + 20 * (i % 10), 10+(i / 10)*SQUARE_LENGTH + 20 * (i / 10), MineRandomArray[i]);
		m_vecMine.push_back(pNew);
	}

	int MineMapArray[3];

	for (int i = 0; i < 3; i++)
	{
		MineMapArray[i] = i % 4;
	}

	for (int i = 0; i < 3; i++)
	{
		MineMap* pNewMapSetting = new MineMap();
		pNewMapSetting->Init(m_pResManager->GetBitMap[RES_TYPE::RES_TYPE_BACKGROUND], m_pResManager->GetBitMap[RES_TYPE::RES_TYPE_01], 
			10 + (i % 10)*EASY_MAP_SIZE + 20 * (i % 10), 10 + (i / 10)* EASY_MAP_SIZE + 20 * (i / 10), MineMapArray[0], 10 + (i % 10)*RESETBOTTON_SIZE + 20 * (i % 10), 10 + (i / 10)* RESETBOTTON_SIZE + 20 * (i / 10), MineMapArray[3]);
		m_vecMineMap.push_back(pNewMapSetting);
	}

}

void GameManager::Draw(HDC hdc)
{
	for (auto iter = m_vecMine.begin(); iter != m_vecMine.end(); ++iter)
	{
		(*iter)->Draw(hdc);
	}
	OptionMapDraw(hdc);
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

	m_pResManager->Release();
	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}


GameManager::~GameManager()
{

}
