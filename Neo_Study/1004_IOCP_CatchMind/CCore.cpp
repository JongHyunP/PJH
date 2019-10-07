#include "CCore.h"
#include "CResManager.h"


DEFINITION_SINGLE(CCore)

CCore::CCore()
{
}


CCore::~CCore()
{
	DESTROY_SINGLE(CResManager);
}

bool CCore::Init(HWND hWnd, HDC hdc)
{
	//리소스 관리자 초기화
	if (!GET_SINGLE(CResManager)->Init(hdc))
	{
		return false;
	}
}

void CCore::Draw(HDC hdc)
{
	//백버퍼에 출력 해주고.

	//마지막 출력
	GET_SINGLE(CResManager)->DrawScene(hdc);
}

void CCore::Update()
{
}

void CCore::Input(POINT pt)
{
}

void CCore::ProcessSocketMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

void CCore::ProcessPacket(char * szBuf, int len)
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
