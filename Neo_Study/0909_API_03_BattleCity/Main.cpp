#include <Windows.h>
#include "MainGame.h"
#include "resource.h"
#include <crtdbg.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	_CrtSetBreakAlloc(174);*/

	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; //��� 0��
	WndClass.cbWndExtra = 0; //��� 0��
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//���ȭ�� �귯��,�̸������ִ� �귯���� (F12 ���� �ö󰡼� ����������)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//Ŀ�� ����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//������ ����
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	//���ν����� �Լ� ������
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	//âũ��

	RegisterClass(&WndClass); //��Ʈ��Ʈ �� ����, ���� ������ �ɼ����� Ŀ���� Ŭ������ �����.

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	//����
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

	OPENFILENAME OFN;
	char str[256];
	char IpstrFile[MAX_PATH] = "";


	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		SetTimer(hWnd, 1, 10, NULL);
		//MainGame::GetInstance()->Init(hWnd, hdc, g_hInst);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_MENU_OPENFILE:
			MainGame::GetInstance()->OpenFile(hWnd);
			break;
		case ID_MENU_SAVEFILE:
			MainGame::GetInstance()->SaveFile(hWnd);
			break;
		}
		return 0;
	case WM_TIMER:
		MainGame::GetInstance()->Update();
		return 0;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		//MainGame::GetInstance()->Input(pt);
		return 0;
	case  WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		MainGame::GetInstance()->Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 800; // �ִ������� �ϴ� �����.
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 600;
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 800;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 600;
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
	//	MainGame::GetInstance()->Release();
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	HWND hRadio;
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		hRadio = GetDlgItem(hDlg, IDC_RADIO1);
//		SendMessage(hRadio, BM_SETCHECK, BST_CHECKED, 0);
//		break;
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK)
//		{
//			if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED)
//				//GameManager::GetInstance()->SetGameMode(GAME_MODE_EASY);
//
//				EndDialog(hDlg, LOWORD(wParam));
//		}
//		else if (LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//		}
//		break;
//	}
//
//	return (INT_PTR)FALSE;
//}