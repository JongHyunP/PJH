#include "CCore.h"
//#include "CResManager.h"
#include "../Scene/SceneManager.h"
#include "../Core/CTimer.h"
#include "../Core/PathManager.h"
#include "../Resources/CResourceManager.h"
#include "../Resources/CTexture.h"

DEFINITION_SINGLE(CCore)
bool CCore::m_bLoop = true;

CCore::CCore()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(); // �ּ���ȣ �˻�()
}


CCore::~CCore()
{
	DESTROY_SINGLE(CTimer);
	DESTROY_SINGLE(PathManager);
	DESTROY_SINGLE(CResourceManager);
	DESTROY_SINGLE(SceneManager);

	ReleaseDC(m_hWnd, m_hDC);
}

bool CCore::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

	CoreRegisterClass();

	//�ػ� ����
	m_tRS.iW = 1280;
	m_tRS.iH = 720;

	//â �����
	Create(); 

	// ȭ�� DC�� �������
	m_hDC = GetDC(m_hWnd);

	//Ÿ�̸� �ʱ�ȭ
	if (!GET_SINGLE(CTimer)->Init())
	{
		return false;
	}

	//��� ������ �ʱ�ȭ
	if (!GET_SINGLE(PathManager)->Init())
	{
		return false;
	}

	//���ҽ� ������ �ʱ�ȭ
	if (!GET_SINGLE(CResourceManager)->Init(hInst,m_hDC))
	{
		return false;
	}

	//�������� �ʱ�ȭ
	if (!GET_SINGLE(SceneManager)->Init())
	{
		return false;
	}

	return true;
}

int CCore::Run()
{
	MSG msg;

	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//������ ����Ÿ���� ���
		else
		{
			Logic();
		}
	}
	
	return (int)msg.wParam;
}

void CCore::Logic()
{
	//Ÿ�̸� ����
	GET_SINGLE(CTimer)->Update();

	float fDeltaTime = GET_SINGLE(CTimer)->GetDeltaTime();

	Input(fDeltaTime);
	Update(fDeltaTime);
	LateUpdate(fDeltaTime);
	Collision(fDeltaTime);
	Render(fDeltaTime);

}

void CCore::Input(float fDeltaTime)
{
	GET_SINGLE(SceneManager)->Input(fDeltaTime);
}

int CCore::Update(float fDeltaTime)
{
	GET_SINGLE(SceneManager)->Update(fDeltaTime);
	return 0;
}

int CCore::LateUpdate(float fDeltaTime)
{
	GET_SINGLE(SceneManager)->LateUpdate(fDeltaTime);
	return 0;
}

void CCore::Collision(float fDeltaTime)
{
	GET_SINGLE(SceneManager)->Collision(fDeltaTime);
}

void CCore::Render(float fDeltaTime)
{
	//������۸�
	CTexture* pBackBuffer = GET_SINGLE(CResourceManager)->GetBackBuffer();

	Rectangle(pBackBuffer->GetDC(), 0, 0, 1280, 720);

	GET_SINGLE(SceneManager)->Render(pBackBuffer->GetDC(),fDeltaTime);

	// ������ ���
	BitBlt(m_hDC, 0, 0, m_tRS.iW, m_tRS.iH, pBackBuffer->GetDC(), 0, 0, SRCCOPY);

	SAFE_RELEASE(pBackBuffer);
}

ATOM CCore::CoreRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = CCore::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"CatchMind";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

BOOL CCore::Create()
{
	m_hWnd = CreateWindowW(L"CatchMind", L"CatchMind", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd) //������ ���� �ڵ� ���п���(null �� ���)
	{
		return FALSE;
	}
	// ���� ������ Ÿ��Ʋ�ٳ� �޴��� ������ �������� ũ�⸦ ������
	RECT rc = { 0, 0, m_tRS.iW, m_tRS.iH };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left,
		rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return TRUE;
}

LRESULT CCore::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	POINT pt;

	switch (iMessage)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
	}
	break;
	//������ ����
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMessage, wParam, lParam);
	}
	return 0;
}
