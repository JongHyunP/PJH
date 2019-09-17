#include "MainGame.h"
#include "ResManager.h"
#include "mecro.h"
#include "EditorObject.h"
#include "MainHeader.h"
#include <iostream>

MainGame* MainGame::m_sThis = nullptr;

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init(HWND hWnd, HDC hdc, HINSTANCE g_hInst)
{
	m_hWnd = hWnd;
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc); 
	m_vecBlockReDoContainer.reserve(1000);
	m_vecBlockUnDoContainer.reserve(1000);

	m_iChoiceBlockNum = 0;

	CreateWindow("button", "Block", WS_CHILD | WS_VISIBLE |BS_GROUPBOX, 545, 5, 220, 420, hWnd, (HMENU)0, g_hInst, NULL);
	r0 = CreateWindow("button", "기본블럭", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		550, 20, 100, 30, hWnd, (HMENU)ID_R0, g_hInst, NULL);
	r1 = CreateWindow("button", "기본블럭↑", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 50, 100, 30, hWnd, (HMENU)ID_R1, g_hInst, NULL);
	r2 = CreateWindow("button", "기본블럭←", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 80, 100, 30, hWnd, (HMENU)ID_R2, g_hInst, NULL);
	r3 = CreateWindow("button", "기본블럭↓", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 110, 100, 30, hWnd, (HMENU)ID_R3, g_hInst, NULL);
	r4 = CreateWindow("button", "기본블럭→", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 140, 100, 30, hWnd, (HMENU)ID_R4, g_hInst, NULL);
	r5 = CreateWindow("button", "실버블럭", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 170, 100, 30, hWnd, (HMENU)ID_R5, g_hInst, NULL);
	r6 = CreateWindow("button", "풀 블럭", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 200, 100, 30, hWnd, (HMENU)ID_R6, g_hInst, NULL);
	r7 = CreateWindow("button", "물 블럭", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 230, 100, 30, hWnd, (HMENU)ID_R7, g_hInst, NULL);
	r8 = CreateWindow("button", "벽 블럭", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 260, 100, 30, hWnd, (HMENU)ID_R8, g_hInst, NULL);
	r9 = CreateWindow("button", "벽 블럭↑", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 290, 100, 30, hWnd, (HMENU)ID_R9, g_hInst, NULL);
	r10 = CreateWindow("button", "벽 블럭←", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 320, 100, 30, hWnd, (HMENU)ID_R10, g_hInst, NULL);
	r11 = CreateWindow("button", "벽 블럭↓", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 350, 100, 30, hWnd, (HMENU)ID_R11, g_hInst, NULL);
	r12 = CreateWindow("button", "벽 블럭→", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		550, 380, 100, 30, hWnd, (HMENU)ID_R12, g_hInst, NULL);

	CheckRadioButton(hWnd, ID_R0, ID_R12, ID_R0);

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
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block13.bmp"), x, y, 25, 25,BLOCK_13);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
					
				}
				else if (i == 15 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 9)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 10)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 14 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else if (i == 15 && j == 11)
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), x, y, 25, 25, BLOCK_00);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
				else
				{
					m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\BlackBack.bmp"), x, y, 25, 25, BLOCK_15);
					x += 25;
					m_vecFixedObject.push_back(m_pObject[j][i]);
				}
			}
			else
			{
				m_pObject[j][i]->Init(m_pResManager->GetBitMap("RES\\GrayBack.bmp"), x, y, 25, 25,BLOCK_16);
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

void MainGame::KeyBoardInput(int virtualKey)
{
	switch (virtualKey)
	{
	case VK_RIGHT:
		for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); ++iter)
		{
			Redo(*iter);
		}
		break;
	case VK_LEFT:
		for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); ++iter)
		{
			Undo(*iter);
		}
		break;
	default:
		break;
	}
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
		sprintf(str, "%s 파일을 저장했습니다.", OFN.lpstrFile);
		MessageBox(hWnd, str, "파일저장 성공", MB_OK);
	}
}

void MainGame::RadioCommand(HWND hWnd, WPARAM wParam)
{
	if (HIWORD(wParam) == BN_CLICKED) {
		switch (LOWORD(wParam)) {
		case ID_R0:
			m_iChoiceBlockNum = BLOCK_00;
			break;
		case ID_R1:
			m_iChoiceBlockNum = BLOCK_01;
			break;
		case ID_R2:
			m_iChoiceBlockNum = BLOCK_02;
			break;
		case ID_R3:
			m_iChoiceBlockNum = BLOCK_03;
			break;
		case ID_R4:
			m_iChoiceBlockNum = BLOCK_04;
			break;
		case ID_R5:
			m_iChoiceBlockNum = BLOCK_05;
			break;
		case ID_R6:
			m_iChoiceBlockNum = BLOCK_06;
			break;
		case ID_R7:
			m_iChoiceBlockNum = BLOCK_07;
			break;
		case ID_R8:
			m_iChoiceBlockNum = BLOCK_08;
			break;
		case ID_R9:
			m_iChoiceBlockNum = BLOCK_09;
			break;
		case ID_R10:
			m_iChoiceBlockNum = BLOCK_10;
			break;
		case ID_R11:
			m_iChoiceBlockNum = BLOCK_11;
			break;
		case ID_R12:
			m_iChoiceBlockNum = BLOCK_12;
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void MainGame::ChangeObject(EditorObject* obj, EditorObject* iter, int blocknum)
{
	//겟 안에 포인터 너무 남발한거 나중에 수정.
	if (blocknum == BLOCK_00)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block00.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_00);
	}
	else if (blocknum == BLOCK_01)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block01.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_01);
	}
	else if (blocknum == BLOCK_02)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block02.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_02);
	}
	else if (blocknum == BLOCK_03)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block03.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_03);
	}
	else if (blocknum == BLOCK_04)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block04.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_04);
	}
	else if (blocknum == BLOCK_05)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block05.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_05);
	}
	else if (blocknum == BLOCK_06)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block06.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_06);
	}
	else if (blocknum == BLOCK_07)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block07.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_07);
	}
	else if (blocknum == BLOCK_08)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block08.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_08);
	}
	else if (blocknum == BLOCK_09)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block09.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_09);
	}
	else if (blocknum == BLOCK_10)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block10.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_10);
	}
	else if (blocknum == BLOCK_11)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block11.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_11);
	}
	else if (blocknum == BLOCK_12)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\block12.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_12);
	}
	else if (blocknum == BLOCK_15)
	{
		obj->Init(m_pResManager->GetBitMap("RES\\BlackBack.bmp"), iter->GetObjectX(), iter->GetObjectY(), 25, 25, BLOCK_15);
	}

}

void MainGame::Redo(EditorObject* iter)
{
	//자신이 입력한 객체들을 저장한걸 팝
	if (m_vecBlockReDoContainer.size() == 0)
	{
		cout << "redo 스택 빔" << endl;
		return;
	}

	if (iter->GetObjectX() == m_vecBlockReDoContainer.back()->GetObjectX() && iter->GetObjectY() == m_vecBlockReDoContainer.back()->GetObjectY())
	{
		cout << "redo 실행" << endl;
		switch (m_vecBlockReDoContainer.back()->GetObjectID())
		{
		case BLOCK_00:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_00);
			break;
		case BLOCK_01:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_01);
			break;
		case BLOCK_02:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_02);
			break;
		case BLOCK_03:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_03);
			break;
		case BLOCK_04:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_04);
			break;
		case BLOCK_05:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_05);
			break;
		case BLOCK_06:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_06);
			break;
		case BLOCK_07:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_07);
			break;
		case BLOCK_08:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_08);
			break;
		case BLOCK_09:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_09);
			break;
		case BLOCK_10:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_10);
			break;
		case BLOCK_11:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_11);
			break;
		case BLOCK_12:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_12);
			break;
		case BLOCK_15:
			ChangeObject(m_vecBlockReDoContainer.back(), iter, BLOCK_15);
			break;
		default:
			break;
		}
		m_vecBlockReDoContainer.pop_back();
	}
}
void MainGame::Undo(EditorObject* iter)
{
	//넘버 저장시켜줘야 어떤건지 언두됨.
	//자신이 넣기전 블럭의 이전 상태를 저장
	if (m_vecBlockUnDoContainer.size() == 0)
	{
		cout << "undo 스택 빔" << endl;
		return;
	}

	if (iter->GetObjectX() == m_vecBlockUnDoContainer.back()->GetObjectX() && iter->GetObjectY() == m_vecBlockUnDoContainer.back()->GetObjectY())
	{
		cout << "undo 실행" << endl;
		
		switch (m_vecBlockUnDoContainer.back()->GetObjectID())
		{
		case BLOCK_00:
			m_pUndoObject = new EditorObject();
			ChangeObject(m_pUndoObject, iter, BLOCK_00);
			iter = m_pUndoObject;
			break;
		case BLOCK_01:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_01);
			break;
		case BLOCK_02:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_02);
			break;
		case BLOCK_03:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_03);
			break;
		case BLOCK_04:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_04);
			break;
		case BLOCK_05:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_05);
			break;
		case BLOCK_06:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_06);
			break;
		case BLOCK_07:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_07);
			break;
		case BLOCK_08:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_08);
			break;
		case BLOCK_09:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_09);
			break;
		case BLOCK_10:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_10);
			break;
		case BLOCK_11:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_11);
			break;
		case BLOCK_12:
			ChangeObject(iter, m_vecBlockUnDoContainer.back(), BLOCK_12);
			break;
		case BLOCK_15:
			m_pUndoObject = new EditorObject();
			ChangeObject(m_pUndoObject, iter, BLOCK_15);
			iter = m_pUndoObject;
			break;
		default:
			break;
		}

		delete m_pUndoObject;
		m_vecBlockUnDoContainer.pop_back();
	}
}

void MainGame::MouseInput(POINT pt)
{
	for (auto iter = m_vecFixedObject.begin(); iter != m_vecFixedObject.end(); ++iter)
	{
		if ((*iter)->Input(pt))
		{
			// 블럭 숫자도 저장해줘야함
			m_vecBlockUnDoContainer.push_back(*iter);
			cout << "언두 저장 : "<<m_vecBlockUnDoContainer.back()->GetObjectID() << endl;
			m_pSelectObject = new EditorObject();
			ChangeObject(m_pSelectObject, *iter, m_iChoiceBlockNum);
			(*iter) = m_pSelectObject;
			m_vecBlockReDoContainer.push_back(*iter);
			cout << "리두 저장 : " << m_vecBlockReDoContainer.back()->GetObjectID() << endl;
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