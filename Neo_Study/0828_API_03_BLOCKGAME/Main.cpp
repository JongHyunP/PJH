#include <Windows.h>
#include "WordRect.h"
#include "GameManager.h"
#include <iostream>
#include <list>

using namespace std;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BLOCKGAME");

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
	while (WM_QUIT != Message.message)
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_NOREMOVE))
		{
			GetMessage(&Message, NULL, 0, 0);
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
		{
			// 여기에 게임루프 실행

		}

	}

	return (int)Message.wParam;
}

SingletonGameManager* gamemanager = SingletonGameManager::getInstance();

int x = 20;
int y = 20;
int speed = 5;
const TCHAR* arr = TEXT("abcd");
//-------------------------------------------
int len;
static TCHAR str[256];
list<TCHAR> lch;
//-------------------------------------------

const TCHAR* nowStage = TEXT("현재 스테이지 : ");
const TCHAR* countPoint = TEXT("점수 : ");
//----------------------------------------------------

bool StringComparison(const TCHAR* str1 , const TCHAR* str)
{
	if (lstrcmp(str1, str))
	{
		return true;
	}

	return false;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W파라미터 L파라미터는 메시지 이외의 부가정보들이 필요할때
{

	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;

	switch (iMessage) //주로 메시지를 재정의 하는데 코딩을 함.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER:
		GetLocalTime(&st);
		y += speed;
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_CHAR:
		len = lstrlen(str);

		if (wParam == VK_BACK) // 백 스페이스일 경우
			memmove(str + (len - 1), str + len, sizeof(TCHAR));
		else if (wParam ==VK_RETURN) //엔터
		{
			memmove(str, str + len, sizeof(TCHAR));
			if (!lstrcmp(arr, str))
			{
				memmove(&arr, &arr + lstrlen(arr), sizeof(TCHAR));
			}
		}
		else
		{
			// WM_CHAR 메시지는 입력된 문자를 wParam으로 전달한다.
			str[len] = (TCHAR)wParam;
			str[len + 1] = 0;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 10, 10, 1200, 800); // A메인 판
		
		Rectangle(hdc, 1210, 10, 1410, 100); // 현황판 위치
		
		Rectangle(hdc, 600, 600, 700, 650); // 입력 위치 사각형

		Rectangle(hdc, 600, 650, 650, 700); // 생명칸 1
		Rectangle(hdc, 650, 650, 700, 700); // 생명칸 2
		Rectangle(hdc, 600, 700, 650, 750); // 생명칸 3
		Rectangle(hdc, 650, 700, 700, 750); // 생명칸 4
		Rectangle(hdc, 600, 750, 650, 800); //생명칸 5
		Rectangle(hdc, 650, 750, 700, 800); //생명칸 6

		Rectangle(hdc, x - 5, y - 5, lstrlen(arr) + 55, y + 25);
		TextOut(hdc, x, y, arr, lstrlen(arr)); // 문자열 출력 (앞으로 이게 랜덤한 x 값에서 떨어질거임)

		TextOut(hdc, 610, 615, str, lstrlen(str)); //입력하는 거
		
		TextOut(hdc, 1220, 20, nowStage, lstrlen(nowStage)); //현재 스테이지 글씨~

		TextOut(hdc, 1220, 40, countPoint, lstrlen(countPoint)); //현재 점수 글씨~

		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //종료메시지
		return 0;//처리햇다.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}