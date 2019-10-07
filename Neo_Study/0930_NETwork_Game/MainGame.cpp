#include "MainGame.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Card.h"
#include "Player.h"

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

void MainGame::ProcessSocketMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen = 0;
	int retval = 0;


	if (WSAGETSELECTERROR(lParam))
	{
		int err_code = WSAGETSELECTERROR(lParam);
		//err_display(WSAGETSELECTERROR(lParam));
		return;
	}

	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
	{
		char szBuf[BUFSIZE];

		retval = recv(wParam, szBuf, BUFSIZE, 0);
		if (retval == SOCKET_ERROR)
		{
			if (WSAGetLastError() != WSAEWOULDBLOCK)
			{
				//cout << "err on recv!!" << endl;
			}
		}

		ProcessPacket(szBuf, retval);
	}
	break;
	case FD_CLOSE:
		closesocket(wParam);
		break;
	}
}

void MainGame::ProcessPacket(char * szBuf, int len)
{
	PACKET_HEADER header;

	memcpy(&header, szBuf, sizeof(header));

	switch (header.wIndex)
	{
	case PACKET_INDEX_LOGIN_RET:
	{
		PACKET_LOGIN_RET packet;
		memcpy(&packet, szBuf, header.wLen);

		m_iIndex = packet.iIndex;
	}
	break;
	case PACKET_INDEX_USER_DATA:
	{
		PACKET_USER_DATA packet;
		memcpy(&packet, szBuf, header.wLen);

	}
	break;
	case PACKET_INDEX_CARD_DATA:
	{
		PACKET_CARD_DATA packet;
		memcpy(&packet, szBuf, header.wLen);
		for (auto iter = m_mapPlayer.begin(); iter != m_mapPlayer.end(); iter++)
		{
			delete iter->second;
		}
		m_mapPlayer.clear();

		for (int i = 0; i < packet.wCount; i++)
		{
			Card* pNew = new Card();
			for (int j = 0; j < 20; j++)
			{
				pNew->m_CardArray[j] = packet.data[i].wArr[j];
				cout << pNew->m_CardArray[j] << " ";
			}
			m_mapPlayer.insert(make_pair(packet.data[i].iIndex, pNew));
		}
	}
	break;
	case PACKET_INDEX_SEND_POS:
	{
		PACKET_SEND_POS packet;
		memcpy(&packet, szBuf, header.wLen);

	}
	break;
	}
}

void MainGame::Draw(HDC hdc)
{
	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		(*iter)->Draw(GET_SINGLE(ResourceManager)->GetBackBuffer());
	}

	GET_SINGLE(ResourceManager)->DrawScene(hdc);
}
