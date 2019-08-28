#include <Windows.h>
#include <vector>
#include <iterator>

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	HDC hdc;
	PAINTSTRUCT ps;

	static int x;
	static int y;
	static BOOL bNowDraw = FALSE;
	static BOOL bNoLine = FALSE;
	static std::vector<int> vx;
	static std::vector<int> vy;

	vx.reserve(1000);
	vy.reserve(1000);

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		vx.push_back(x);
		vy.push_back(y);
		bNowDraw = TRUE;
		return 0;
	case WM_MOUSEMOVE:
		if (bNowDraw == TRUE)
		{
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			vx.push_back(x);
			vy.push_back(y);
		}
		return 0;
	case WM_LBUTTONUP:
		bNowDraw = FALSE;
		return 0;

	case WM_PAINT:
		hdc = GetDC(hWnd);

		MoveToEx(hdc, vx[0], vy[0],NULL);

		for (int i = 0; i < vx.size(); ++i)
		{
			LineTo(hdc, vx[i], vy[i]);
			
			MoveToEx(hdc, vx[i], vy[i], NULL);
		}
		ReleaseDC(hWnd, hdc);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}