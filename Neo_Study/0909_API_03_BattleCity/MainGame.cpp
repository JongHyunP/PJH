#include "MainGame.h"
#include "ResManager.h"
#include "mecro.h"
#include "EditorObject.h"

MainGame* MainGame::m_sThis = nullptr;

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init(HWND hWnd, HDC hdc)
{
	m_hWnd = hWnd;
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc); 

	// 뭔가 벡터로 블럭모양 다 저장한다음에 뽑아서 교체.


	//고정 만들고
	int x = 0;
	int y = 0;

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			m_pObject[j][i] = new EditorObject();

			if (i <= 15 && j <= 20)
			{
				if (i == 15 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block13.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
					
				}
				else if (i == 15 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 15 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\BlackBack.bmp"), x, y, 25, 25);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
			}
			else
			{
				m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\GrayBack.bmp"), x, y, 25, 25);
				x += 25;
				m_vecFixedObject.push_back(m_pObject[j][i]);
			}
		}
		x = 0;
		y += 25;
	}

}

void MainGame::Draw(HDC hdc)
{
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); iter++)
	{
		(*iter)->Draw(m_pResManager->GetBackBuffer(),true);
	}
	m_pResManager->DrawScene(hdc);
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

void MainGame::Input(POINT pt)
{
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); ++iter)
	{
		if ((*iter)->Input(pt))
		{
			(*iter)->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), pt.x, pt.y, 25, 25);
			InvalidateRect(m_hWnd, NULL, false);
		}
		
	}
}

void MainGame::Release()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			delete m_pObject[j][i];
		}
	}

	m_pResManager->Release();
	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}