#include <Windows.h>
#include <math.h>

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
//void DrawCircle(HDC hdc, int x, int y, int xR, int yR)

#define PI 3.141592

float DegreeToRadian(float degree)
{
	return (PI / 180) * degree;
}


//cosf(s) = x/r  ->> cosf(s)*r = _x(�������̵�) + x;
void DrawCircle(HDC hdc, int x, int y, int xR)
{
	MoveToEx(hdc, x+xR, y, NULL);

	for (int i = 0; i < 360; i++)
	{
		int _x = cosf(DegreeToRadian(i)) * xR + x;
		int _y = sinf(DegreeToRadian(i)) * xR + y;

		//SetPixel(hdc, _x, _y, RGB(255, 0, 0));
		LineTo(hdc, _x, _y);
	}

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		/*Rectangle(hdc, 50, 100, 200, 200);
		Ellipse(hdc, 50, 100, 100, 200);
		MoveToEx(hdc, 50, 150, NULL);
		LineTo(hdc, 125, 100);
		MoveToEx(hdc, 125, 100, NULL);
		LineTo(hdc, 200, 150);
		MoveToEx(hdc, 200, 150, NULL);
		LineTo(hdc, 125, 200);
		MoveToEx(hdc, 125, 200, NULL);
		LineTo(hdc, 50, 150);*/

		DrawCircle(hdc, 200, 200, 100);
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}