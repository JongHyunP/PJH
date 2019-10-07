#pragma once
#include "value.h"
#include "..\..\..\..\..\..\Administrator\source\repos\Study_Server-NEO-\\0918_SERVER_01\1004_CompletionPort_Model\PACKET_HEADER_CATCH_MIND.h" //네오플용

class CCore
{
	DECLARE_SINGLE(CCore)
private:
	int				m_iIndex = 0;
public:
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Update();
	void Input(POINT pt);
	void ProcessSocketMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ProcessPacket(char * szBuf, int len);
};

