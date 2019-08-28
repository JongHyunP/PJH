#include <Windows.h>
#include <math.h>
#include <vector>

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

#define PI 3.141592

static int  circle_x =600;
static int  circle_y = 350;

static int speed_x = 5;
static int speed_y = 5;


static int player_x = 400;
static int player_y = 400;

static float distance = 0;

float DegreeToRadian(float degree)
{
	return (PI / 180) * degree;
}

void DrawCircle(HDC hdc, int x, int y, int xR)
{
	MoveToEx(hdc, x + xR, y, NULL);

	for (int i = 0; i < 360; i++)
	{
		int _x = cosf(DegreeToRadian(i)) * xR + x;
		int _y = sinf(DegreeToRadian(i)) * xR + y;

		LineTo(hdc, _x, _y);
	}

}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W파라미터 L파라미터는 메시지 이외의 부가정보들이 필요할때
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	static TCHAR sTime[128];

	switch (iMessage) //주로 메시지를 재정의 하는데 코딩을 함.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER: //1초마다 한번씩 실행됨.
		GetLocalTime(&st);
	
		circle_x= circle_x + speed_x;

		if (circle_x >= 650)
		{
			circle_x = circle_x - speed_x;
			speed_x = speed_x * -1;
		}
		else if (circle_x <= 350)
		{
			//circle_x = circle_x + speed_x;
			speed_x = speed_x * -1;
		}
		

		if (distance < 60) //임시
		{
			speed_x = 0;
			SendMessage(hWnd, WM_DESTROY, 0, 0);
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		distance = sqrt(((circle_x - player_x) * (circle_x - player_x)) + ((circle_y - player_y) * (circle_y - player_y)));

		Rectangle(hdc, 300, 100, 700, 700);
		DrawCircle(hdc, circle_x, circle_y, 50);
		DrawCircle(hdc, player_x, player_y, 10);

		EndPaint(hWnd, &ps);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			player_x -= 8;
			break;
		case VK_RIGHT:
			player_x += 8;
			break;
		case VK_UP:
			player_y -= 8;
			break;
		case VK_DOWN:
			player_y += 8;
			break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

	case WM_DESTROY: //WM = 윈도우메시지 줄임말
		MessageBox(hWnd, TEXT("부딫혔습니다!!!"), TEXT("충돌박스"), MB_OK);
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //종료메시지
		return 0;//처리햇다.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}