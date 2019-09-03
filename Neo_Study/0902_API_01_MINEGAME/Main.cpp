#include <windows.h>
#include "GameManager.h"
#include "resource.h"
#include <crtdbg.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtDumpMemoryLeaks();
	//_CrtSetBreakAlloc(174);

	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; //통상 0임
	WndClass.cbWndExtra = 0; //통상 0임
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//배경화면 브러쉬,미리쓸수있는 브러쉬들 (F12 참조 올라가서 색볼수있음)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//커서 변경
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//아이콘 변경
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	//프로시저의 함수 포인터
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	//창크기

	RegisterClass(&WndClass); //스트럭트 로 전달, 위에 설정한 옵션으로 커스텀 클래스를 만든다.

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	//메인
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
	POINT pt;

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		SetTimer(hWnd, 1, 1000, NULL);
		GameManager::GetInstance()->Init(hWnd, hdc, g_hInst);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_MENU_LEVELCONTROL:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, SettingDlg);
			break;
		}
		return 0;
	case WM_TIMER:
		GameManager::GetInstance()->Update();
		return 0;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		GameManager::GetInstance()->InputLeftButton(pt);
		return 0;
	case WM_RBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		GameManager::GetInstance()->InputRightButton(pt);
		return 0;
	case  WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GameManager::GetInstance()->Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		GameManager::GetInstance()->Release();
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hRadio;
	switch (message)
	{
	case WM_INITDIALOG:
		hRadio = GetDlgItem(hDlg, IDC_RADIO1);
		SendMessage(hRadio, BM_SETCHECK, BST_CHECKED, 0);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED)
				//GameManager::GetInstance()->SetGameMode(GAME_MODE_EASY);

				EndDialog(hDlg, LOWORD(wParam));
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
		}
		break;
	}

	return (INT_PTR)FALSE;
}