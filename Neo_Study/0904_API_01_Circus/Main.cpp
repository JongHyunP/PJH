#include <Windows.h>

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

#define IMAGE_NUM 5

HDC g_MemDC[IMAGE_NUM];
HBITMAP g_hBitMap[IMAGE_NUM];
HBITMAP g_hOld[IMAGE_NUM];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x = 100;
	static int y = 550;

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		hdc = GetDC(hWnd);
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

		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		//BitBlt(g_MemDC[0], 0, 0, 1024, 768, g_MemDC[1], 0, -590, SRCCOPY);
		BitBlt(g_MemDC[0], x, y, 1024, 768, g_MemDC[1], -50, -590, SRCCOPY);

		//�ܵ��
		for (int i = 0; i < 20; i++)
		{
			TransparentBlt(g_MemDC[0], 100*i, 380, 100, 420, g_MemDC[1], 0, 0, 67, 183, RGB(255, 0, 255));
		}

		//����
		for (int i = 0; i < 20; i++)
		{
			TransparentBlt(g_MemDC[0], 100*i, 200, 100, 150, g_MemDC[3], 0, 0, 65, 64, RGB(255, 0, 255));
		}
		//���� �ڳ���
		TransparentBlt(g_MemDC[0], 100, 200, 100, 150, g_MemDC[4], 0, 0, 66, 67, RGB(255, 0, 255));

		//�÷��̾� ��ġ
		TransparentBlt(g_MemDC[0], x, y, 100, 150, g_MemDC[2], 0, 0, 66, 63, RGB(255, 0, 255));

		//����°�
		BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[0], 0, 0, SRCCOPY);

		//for (int i = 0; i < IMAGE_NUM; i++)
		//{
		//	DeleteObject(SelectObject(g_MemDC[i], g_hOld[i])); // ���� ������� �� �� ����
		//	DeleteDC(g_MemDC[i]);
		//}
		//InvalidateRect(hWnd, NULL, false);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			x -= 8;
			break;
		case VK_RIGHT:
			x += 8;
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
	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}