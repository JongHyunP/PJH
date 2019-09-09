#include <Windows.h>
#include "MainGame.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWnd;
LPCTSTR lpszClass = TEXT("Hello World!!");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, NULL);
		hdc = GetDC(hWnd);
		MainGame::GetInstance()->Init(hWnd, hdc);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		MainGame::GetInstance()->Draw(hdc);
		EndPaint(hWnd, &ps);
	}
	return 0;
	case WM_KEYDOWN:
		MainGame::GetInstance()->Input(wParam,true);
		return 0;
	case WM_KEYUP:
		MainGame::GetInstance()->Input(wParam, false);
		return 0;
	case WM_TIMER:
	{
		MainGame::GetInstance()->Update();
		InvalidateRect(hWnd, NULL, false);
	}
	return 0;
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 800; // 최대사이즈로 일단 실행됨.
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 600;
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 800;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 600;
		return 0;
	case WM_DESTROY:
		MainGame::GetInstance()->Release();
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;

	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}