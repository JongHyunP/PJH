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


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	static TCHAR sTime[128];

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER: //1�ʸ��� �ѹ��� �����.
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
		

		if (distance < 60) //�ӽ�
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

	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		MessageBox(hWnd, TEXT("�΋H�����ϴ�!!!"), TEXT("�浹�ڽ�"), MB_OK);
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}