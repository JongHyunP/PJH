#include "GameManager.h"
#include "ResManager.h"
#include "mecro.h"


GameManager* GameManager::m_sThis = nullptr;

GameManager::GameManager()
{
	m_pResManager = nullptr;
}

void GameManager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_hWnd = hWnd;

	m_pResManager = new ResManager();
	m_pResManager->Init(hdc);

}

void GameManager::Draw(HDC hdc)
{

}

void GameManager::InputKeyBoard(WPARAM wParam, HWND hWnd)
{
	switch (wParam) {
	case VK_LEFT:
		//x -= 8;
		break;
	case VK_RIGHT:
		//x += 8;
		break;
	case VK_UP:
		//y -= 8;
		break;
	case VK_DOWN:
		//y += 8;
		break;
	}
	InvalidateRect(hWnd, NULL, false);
}

void GameManager::Release()
{
	m_pResManager->Release();
	SAFE_DELETE(m_pResManager);
	SAFE_DELETE(m_sThis);
}