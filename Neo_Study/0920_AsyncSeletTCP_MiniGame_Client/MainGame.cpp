#include "MainGame.h"
#include "ResManager.h"
#include "BoardTile.h"
#include "ChessPieceManager.h"

DEFINITION_SINGLE(MainGame)

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	DESTROY_SINGLE(ChessPieceManager);
	DESTROY_SINGLE(ResManager);
}

bool MainGame::Init(HWND hWnd, HDC hdc)
{
	//���ҽ� ������ �ʱ�ȭ
	if (!GET_SINGLE(ResManager)->Init(hdc))
	{
		return false;
	}
	
	// ü���� ������ �ʱ�ȭ.
	if (!GET_SINGLE(ChessPieceManager)->Init(hWnd,hdc))
	{
		return false;
	}

	return true;
}

void MainGame::Draw(HDC hdc)
{
	GET_SINGLE(ChessPieceManager)->Draw(GET_SINGLE(ResManager)->GetBackBuffer());

	GET_SINGLE(ResManager)->DrawScene(hdc);
}

void MainGame::Update()
{

}

void MainGame::Input(POINT pt)
{
	GET_SINGLE(ChessPieceManager)->Input(pt);
}