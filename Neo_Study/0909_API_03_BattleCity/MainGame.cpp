#include "MainGame.h"
#include "ResManager.h"
#include "mecro.h"

MainGame* MainGame::m_sThis = nullptr;

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init(HWND hWnd, HDC hdc)
{
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc); 

	//고정 만들고
}

void MainGame::Draw(HDC hdc)
{

}

void MainGame::Update()
{

}

void MainGame::OpenFile(HWND hWnd)
{
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0Text File\0.txt;*.ini\0";
	OFN.lpstrFile = IpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";

	if (GetOpenFileName(&OFN) != 0)
	{
		sprintf(str, "%s 파일을 선택했습니다.", OFN.lpstrFile);
		MessageBox(hWnd, str, "파일열기 성공", MB_OK);
	}
}

void MainGame::SaveFile(HWND hWnd)
{
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0Text File\0.txt;*.ini\0";
	OFN.lpstrFile = IpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";

	if (GetSaveFileName(&OFN) != 0)
	{
		sprintf(str, "%s 파일을 선택했습니다.", OFN.lpstrFile);
		MessageBox(hWnd, str, "파일열기 성공", MB_OK);
	}
}

void MainGame::Input(int virtualKey, bool iskeydown)
{

}

void MainGame::Release()
{
	m_pResManager->Release();

	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}