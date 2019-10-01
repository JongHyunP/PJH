#include "MainGame.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Card.h"

DEFINITION_SINGLE(MainGame)

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecCard.clear();

	DESTROY_SINGLE(ResourceManager);
	DESTROY_SINGLE(SceneManager);
}

bool MainGame::Init(HWND hWnd, HDC hdc)
{
	//리소스 관리자 초기화
	if (!GET_SINGLE(ResourceManager)->Init(hdc))
	{
		return false;
	}

	if (!GET_SINGLE(SceneManager)->Init())
	{
		return false;
	}

	m_eState = GAME_STATE_WAIT;
	m_pSelectOne = nullptr;
	m_pSelectTwo = nullptr;

	m_dwCount = 0;
	m_hWnd = hWnd;
	srand(GetTickCount());

	int iArray[20];

	for (int i = 0; i < 20; i++)
		iArray[i] = i % 10;

	for (int i = 0; i < 100; i++)
	{
		int randA = rand() % 20;
		int randB = rand() % 20;

		int iTemp = iArray[randA];
		iArray[randA] = iArray[randB];
		iArray[randB] = iTemp;
	}

	for (int i = 0; i < 20; i++)
	{
		stringstream intToString;
		intToString << iArray[i];

		Card* pNew = new Card();
		pNew->Init(GET_SINGLE(ResourceManager)->GetBitMap("RES\\0" + intToString.str() + ".bmp"), GET_SINGLE(ResourceManager)->GetBitMap("RES\\back.bmp"),
			(i % 10) * CARD_WIDTH + 10 * (i % 10), (i / 10) * CARD_HEIGHT + 10 * (i / 10), iArray[i]);

		m_vecCard.push_back(pNew);
	}


	return true;
}


void MainGame::Update()
{
	if (m_eState != GAME_STATE_SHOW)
		return;

	m_dwCount++;

	if (m_dwCount == 100)
	{
		m_dwCount = 0;
		m_pSelectOne->SetClose();
		m_pSelectTwo->SetClose();
		m_pSelectOne = nullptr;
		m_pSelectTwo = nullptr;
		m_eState = GAME_STATE_WAIT;
		InvalidateRect(m_hWnd, NULL, false);
	}
}

void MainGame::Input(POINT pt)
{
	if (m_eState == GAME_STATE_SHOW)
		return;

	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		if ((*iter)->Input(pt))
		{
			if (m_eState == GAME_STATE_WAIT)
			{
				m_pSelectOne = *iter;
				m_eState = GAME_STATE_ONE;
			}
			else if (m_eState == GAME_STATE_ONE)
			{
				m_pSelectTwo = *iter;
				if (m_pSelectTwo->GetID() == m_pSelectOne->GetID())
				{
					m_eState = GAME_STATE_WAIT;
				}
				else
				{
					m_eState = GAME_STATE_SHOW;
				}
			}

			InvalidateRect(m_hWnd, NULL, false);
		}
	}
}

void MainGame::SendCardInfo()
{
	PACKET_SEND_CARDINFO packet;

	packet.header.wIndex = PACKET_INDEX_SEND_CARDINFO;
	packet.header.wLen = sizeof(packet);
	packet.data.iIndex = g_iIndex;
}

void MainGame::Draw(HDC hdc)
{
	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		(*iter)->Draw(GET_SINGLE(ResourceManager)->GetBackBuffer());
	}

	GET_SINGLE(ResourceManager)->DrawScene(hdc);
}
