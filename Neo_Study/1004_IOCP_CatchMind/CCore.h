#pragma once
#include "value.h"

class CCore
{
	DECLARE_SINGLE(CCore)
private:
	int				m_iIndex = 0;

private:
	static	bool m_bLoop;

private:
	HINSTANCE	 m_hInst;
	HWND		 m_hWnd;
	HDC			 m_hDC;
	RESOLUTION	 m_tRS;

public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	void Logic();
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(float fDeltaTime);
private:
	ATOM CoreRegisterClass();
	BOOL Create();
public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

