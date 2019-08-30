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
	WndClass.lpszMenuName = NULL;
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

HDC hMemDC;
HBITMAP hBitMap;
HBITMAP hOldBitMap;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	HDC hdc;
	SYSTEMTIME st;
	PAINTSTRUCT ps;
	int aniNum = 0;

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);//�޸� �𾾸� ����� �۾�
		hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1)); //(���ҽ��� ������, ���ҽ� ���̵� ������ ���ҽ��� �������°�)
		hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
		ReleaseDC(hWnd,hdc);
		return 0;
	case WM_TIMER:
		GetLocalTime(&st);
		if (aniNum == 0)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1)); //(���ҽ��� ������, ���ҽ� ���̵� ������ ���ҽ��� �������°�)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 1)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2)); //(���ҽ��� ������, ���ҽ� ���̵� ������ ���ҽ��� �������°�)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 2)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3)); //(���ҽ��� ������, ���ҽ� ���̵� ������ ���ҽ��� �������°�)
			hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
			ReleaseDC(hWnd, hdc);
			aniNum++;
		}
		else if (aniNum == 3)
		{
			hdc = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hdc);
			hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4)); //(���ҽ��� ������, ���ҽ� ���̵� ������ ���ҽ��� �������°�)
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
	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		SelectObject(hMemDC, hOldBitMap);
		DeleteObject(hBitMap);
		DeleteDC(hMemDC);
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}