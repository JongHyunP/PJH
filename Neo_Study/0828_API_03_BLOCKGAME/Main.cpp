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
			// ���⿡ ���ӷ��� ����

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

const TCHAR* nowStage = TEXT("���� �������� : ");
const TCHAR* countPoint = TEXT("���� : ");
//----------------------------------------------------

bool StringComparison(const TCHAR* str1 , const TCHAR* str)
{
	if (lstrcmp(str1, str))
	{
		return true;
	}

	return false;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{

	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
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

		if (wParam == VK_BACK) // �� �����̽��� ���
			memmove(str + (len - 1), str + len, sizeof(TCHAR));
		else if (wParam ==VK_RETURN) //����
		{
			memmove(str, str + len, sizeof(TCHAR));
			if (!lstrcmp(arr, str))
			{
				memmove(&arr, &arr + lstrlen(arr), sizeof(TCHAR));
			}
		}
		else
		{
			// WM_CHAR �޽����� �Էµ� ���ڸ� wParam���� �����Ѵ�.
			str[len] = (TCHAR)wParam;
			str[len + 1] = 0;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 10, 10, 1200, 800); // A���� ��
		
		Rectangle(hdc, 1210, 10, 1410, 100); // ��Ȳ�� ��ġ
		
		Rectangle(hdc, 600, 600, 700, 650); // �Է� ��ġ �簢��

		Rectangle(hdc, 600, 650, 650, 700); // ����ĭ 1
		Rectangle(hdc, 650, 650, 700, 700); // ����ĭ 2
		Rectangle(hdc, 600, 700, 650, 750); // ����ĭ 3
		Rectangle(hdc, 650, 700, 700, 750); // ����ĭ 4
		Rectangle(hdc, 600, 750, 650, 800); //����ĭ 5
		Rectangle(hdc, 650, 750, 700, 800); //����ĭ 6

		Rectangle(hdc, x - 5, y - 5, lstrlen(arr) + 55, y + 25);
		TextOut(hdc, x, y, arr, lstrlen(arr)); // ���ڿ� ��� (������ �̰� ������ x ������ ����������)

		TextOut(hdc, 610, 615, str, lstrlen(str)); //�Է��ϴ� ��
		
		TextOut(hdc, 1220, 20, nowStage, lstrlen(nowStage)); //���� �������� �۾�~

		TextOut(hdc, 1220, 40, countPoint, lstrlen(countPoint)); //���� ���� �۾�~

		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}