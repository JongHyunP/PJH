#include <Windows.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR IpszClass = TEXT("First");

void RectangleCheak(HDC hdc, int MyRight, int ComLeft, int MyBottom, int ComTop, int MyLeft, int ComRight, int MyTop, int ComBottom);  //사각형 충돌

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
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
	WndClass.lpszClassName = IpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(IpszClass, IpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);

		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

bool bLive = TRUE;
RECT MyRect, ComRect;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HPEN MyPen, OldPen;
	HPEN MyCOM, OldCOM;

	static int x = 100;
	static int y = 100;

	//사용자
	MyRect.left = 50 + x;
	MyRect.top = 50 + y;
	MyRect.right = 100 + x;
	MyRect.bottom = 110 + y;

	//컴퓨터
	ComRect.left = 300;
	ComRect.top = 300;
	ComRect.right = 500;
	ComRect.bottom = 500;

	switch (iMessage)
	{
		/*case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_LEFT:
		{
		x-=8;
		}
		break;
		case VK_RIGHT:
		{
		x+=8;
		}
		break;
		case VK_UP:
		{
		y-=8;
		}
		break;
		case VK_DOWN:
		{
		y+=8;
		}
		break;
		}
		InvalidateRect(hWnd,NULL,TRUE);
		break;*/

	case WM_KEYDOWN:
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			x -= 8;

		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			y -= 8;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x += 8;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y += 8;
		}
	}
	InvalidateRect(hWnd, NULL, TRUE);

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		MyCOM = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
		OldCOM = (HPEN)SelectObject(hdc, MyCOM);
		if (bLive)
		{
			Rectangle(hdc, ComRect.left, ComRect.top, ComRect.right, ComRect.bottom);
		}

		MyPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
		OldPen = (HPEN)SelectObject(hdc, MyPen);
		Rectangle(hdc, MyRect.left, MyRect.top, MyRect.right, MyRect.bottom);

		//충돌체크
		TextOut(hdc, 0, 0, TEXT("충돌 X"), strlen("충돌 X"));

		RECT Temp;
		if (IntersectRect(&Temp, &MyRect, &ComRect))
		{
			TextOut(hdc, 0, 0, TEXT("충돌 0"), strlen("충돌 0"));
			
			Temp = Temp;
			bLive = FALSE;
		}
		bLive = TRUE;

		//RectangleCheak( hdc, MyRect.right, ComRect.left,MyRect.bottom, ComRect.top, MyRect.left, ComRect.right, MyRect.top, ComRect.bottom );

		SelectObject(hdc, OldCOM);
		DeleteObject(MyCOM);
		SelectObject(hdc, OldPen);
		DeleteObject(MyPen);

		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
}



void RectangleCheak(HDC hdc, int MyRight, int ComLeft, int MyBottom, int ComTop, int MyLeft, int ComRight, int MyTop, int ComBottom)  //사각형 충돌
{


	/*
	if( MyRight >= ComLeft && MyBottom > ComTop && MyLeft <= ComRight &&  MyTop < ComBottom )
	{

	TextOut(hdc,0,0,TEXT("충돌 0"),strlen("충돌 0"));
	bLive = FALSE;
	//MessageBox(hWnd,"충돌","충돌",MB_OK);
	}
	else
	{
	bLive = TRUE;
	}
	*/
}
