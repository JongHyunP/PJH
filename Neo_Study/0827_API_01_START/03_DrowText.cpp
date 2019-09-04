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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) // W�Ķ���� L�Ķ���ʹ� �޽��� �̿��� �ΰ��������� �ʿ��Ҷ�
{
	//HDC hdc;
	//PAINTSTRUCT ps;
	//RECT rt = { 100,100,400,300 };
	//const TCHAR* str = TEXT("���� �����ϴ�. �ƾ�~~");

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt = { 100,100,400,300 };
	const TCHAR* str = TEXT("�ƾ� ������ ¯�Դϴ�.. �ƾ�..");

	switch (iMessage) //�ַ� �޽����� ������ �ϴµ� �ڵ��� ��.
	{
	case WM_DESTROY: //WM = ������޽��� ���Ӹ�
		PostQuitMessage(0); //����޽���
		return 0;//ó���޴�.
	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);
	//	DrawText(hdc, str, -1, &rt, DT_CENTER | DT_WORDBREAK);
	//	EndPaint(hWnd, &ps);
	//	return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawText(hdc, str, -1, &rt, DT_CENTER | DT_WORDBREAK);
		// ����° ���ڰ� -1 �� ���ڿ����� �ε� -1�� ��� �� ���� ���ڿ����� �����.
		EndPaint(hWnd, &ps);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}