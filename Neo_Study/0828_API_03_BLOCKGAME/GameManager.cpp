#include "GameManager.h"


SingletonGameManager* SingletonGameManager::sGameManager = nullptr;


void SingletonGameManager::Update()
{
}

void SingletonGameManager::Render(HDC hdc, float a)
{
}

void SingletonGameManager::Input(WPARAM wParam)
{
	pInput->PlayerInputWord(wParam);
}

void SingletonGameManager::keyDraw(HDC hdc)
{
	pInput->PlayerInputWordPaint(hdc);
}
