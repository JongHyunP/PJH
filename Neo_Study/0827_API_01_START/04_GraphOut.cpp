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
//void DrawCircle(HDC hdc, int x, int y, int xR, int yR)

#define PI 3.141592

float DegreeToRadian(float degree)
{
	return (PI / 180) * degree;
}


//cosf(s) = x/r  ->> cosf(s)*r = _x(기준점이동) + x;
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W파라미터 L파라미터는 메시지 이외의 부가정보들이 필요할때
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) //주로 메시지를 재정의 하는데 코딩을 함.
	{
	case WM_DESTROY: //WM = 윈도우메시지 줄임말
		PostQuitMessage(0); //종료메시지
		return 0;//처리햇다.
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