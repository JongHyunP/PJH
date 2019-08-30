#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
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
	WndClass.lpszMenuName = NULL;
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

HDC hMemDC;
HBITMAP hBitMap;
HBITMAP hOldBitMap;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W파라미터 L파라미터는 메시지 이외의 부가정보들이 필요할때
{
	HDC hdc;
	SYSTEMTIME st;
	PAINTSTRUCT ps;
	int aniNum = 0;

	switch (iMessage) //주로 메시지를 재정의 하는데 코딩을 함.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);//메모리 디씨를 만드는 작업
		hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1)); //(리소스의 포인터, 리소스 아이디를 가지고 리소스를 가져오는거)
		hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
		ReleaseDC(hWnd,hdc);
		return 0;
	case WM_TIMER:
		GetLocalTime(&st);
		if (aniNum == 0)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1)); //(리소스의 포인터, 리소스 아이디를 가지고 리소스를 가져오는거)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 1)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2)); //(리소스의 포인터, 리소스 아이디를 가지고 리소스를 가져오는거)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 2)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3)); //(리소스의 포인터, 리소스 아이디를 가지고 리소스를 가져오는거)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 3)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4)); //(리소스의 포인터, 리소스 아이디를 가지고 리소스를 가져오는거)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum=0;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BitBlt(hdc, 100, 100, 100, 100, hMemDC, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY: //WM = 윈도우메시지 줄임말
		SelectObject(hMemDC, hOldBitMap);
		DeleteObject(hBitMap);
		DeleteDC(hMemDC);
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //종료메시지
		return 0;//처리햇다.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}