#pragma once
#include "value.h"
//#include "..\..\..\..\..\..\Administrator\source\repos\Study_Server-NEO-\0918_SERVER_01\Common\PACKET_HEADER.h" //네오플용
#include "..\..\..\Study_Server-NEO-\0918_SERVER_01\Common\PACKET_HEADER.h" //집용

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_ONE,
	GAME_STATE_SHOW
};

class Card;

class Player;

class MainGame
{
	DECLARE_SINGLE(MainGame)

private:
	unordered_map<int, Card*> m_mapPlayer;
	vector<Card*>	m_vecCard;
	HWND			m_hWnd;
	GAME_STATE		m_eState;
	Card*			m_pSelectOne;
	Card*			m_pSelectTwo;
	DWORD			m_dwCount;
	int				m_iIndex = 0;
public:

	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Input(POINT pt);
	void ProcessSocketMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ProcessPacket(char* szBuf, int len);
	void Update();
	void Release();

};

