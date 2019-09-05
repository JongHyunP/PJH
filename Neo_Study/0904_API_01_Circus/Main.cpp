#include <Windows.h>
#include "GameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Circus");

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

#define IMAGE_NUM 6
#define MAX_SIZE  2000
#define WIN_X 1024
#define WIN_Y 768

HDC g_MemDC[IMAGE_NUM];
HBITMAP g_hBitMap[IMAGE_NUM];
HBITMAP g_hOld[IMAGE_NUM];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W파라미터 L파라미터는 메시지 이외의 부가정보들이 필요할때
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x = 100;
	static int y = 550;
	static int Nx = 0;

	switch (iMessage) //주로 메시지를 재정의 하는데 코딩을 함.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		hdc = GetDC(hWnd);
	//	GameManager::GetInstance()->Init(hWnd, hdc, g_hInst);

		g_MemDC[0] = CreateCompatibleDC(hdc);
		g_hBitMap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[0] = (HBITMAP)SelectObject(g_MemDC[0], g_hBitMap[0]);
		
		g_MemDC[1] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitMap[1] = (HBITMAP)LoadImage(NULL, "Res\\back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[1] = (HBITMAP)SelectObject(g_MemDC[1], g_hBitMap[1]);

		g_MemDC[2] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitMap[2] = (HBITMAP)LoadImage(NULL, "Res\\player0.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[2] = (HBITMAP)SelectObject(g_MemDC[2], g_hBitMap[2]);

		g_MemDC[3] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitMap[3] = (HBITMAP)LoadImage(NULL, "Res\\back_normal.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[3] = (HBITMAP)SelectObject(g_MemDC[3], g_hBitMap[3]);

		g_MemDC[4] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitMap[4] = (HBITMAP)LoadImage(NULL, "Res\\back_deco.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[4] = (HBITMAP)SelectObject(g_MemDC[4], g_hBitMap[4]);

		g_MemDC[5] = CreateCompatibleDC(hdc);
		g_hBitMap[5] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[5] = (HBITMAP)SelectObject(g_MemDC[5], g_hBitMap[5]);

		////잔디밭
		for (int i = 0; i < 20; i++)
		{
			TransparentBlt(g_MemDC[0], 100 * i, 380, 100, 420, g_MemDC[1], 0, 0, 67, 183, RGB(255, 0, 255));
		}

		////관중
		for (int i = 0; i < 20; i++)
		{
			TransparentBlt(g_MemDC[0], 100 * i, 200, 100, 150, g_MemDC[3], 0, 0, 65, 64, RGB(255, 0, 255));
		}
		////관중 코끼리
		TransparentBlt(g_MemDC[0], 100, 200, 100, 150, g_MemDC[4], 0, 0, 66, 67, RGB(255, 0, 255));

		return 0;

	case WM_TIMER:
		//GameManager::GetInstance()->Update();
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//GameManager::GetInstance()->Draw(hdc);
		//BitBlt(g_MemDC[0], 0, 0, 1024, 768, g_MemDC[1], 0, -590, SRCCOPY);
		//BitBlt(g_MemDC[0], x, y, 1024, 768, g_MemDC[1], -50, -590, SRCCOPY);

		

		////플레이어 위치
	//	TransparentBlt(g_MemDC[0], x, y, 100, 150, g_MemDC[2], 0, 0, 66, 63, RGB(255, 0, 255));

		////덮어쓰는것
		//BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[0], 0, 0, SRCCOPY);

		//그림 전체에서 움직여주는걸로 0이 빽버퍼, 1이 그림전체
		if (Nx < 0)
		{
			BitBlt(g_MemDC[5], 0, 0, -Nx, WIN_Y, g_MemDC[0], MAX_SIZE + Nx, 0, SRCCOPY);
			BitBlt(g_MemDC[5], -Nx, 0, WIN_X + Nx, WIN_Y, g_MemDC[0], 0, 0, SRCCOPY);

			BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[5], 0, 0, SRCCOPY);
		}
		else
		{
			BitBlt(g_MemDC[5], 0, 0, WIN_X, WIN_Y, g_MemDC[0], Nx, 0, SRCCOPY);
			BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[5], 0, 0, SRCCOPY);
		}

		if (Nx + WIN_X >= 2000)
		{
			Nx -= MAX_SIZE;
		}
		//for (int i = 0; i < IMAGE_NUM; i++) // 스크롤 지나가면 없애고
		//{
		//	DeleteObject(SelectObject(g_MemDC[i], g_hOld[i])); // 종이 원래대로 한 후 제거
		//	DeleteDC(g_MemDC[i]);
		//}
		//InvalidateRect(hWnd, NULL, false);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			Nx -= 100;
			break;
		case VK_RIGHT:
			Nx += 100;
			break;
		case VK_UP:
			y -= 8;
			break;
		case VK_DOWN:
			y += 8;
			break;
		default:
			break;
		}
       InvalidateRect(hWnd, NULL, false);
		return 0;
	case WM_DESTROY: //WM = 윈도우메시지 줄임말
		KillTimer(hWnd, 1);
	//	GameManager::GetInstance()->Release();
		PostQuitMessage(0); //종료메시지
		return 0;//처리햇다.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}