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
	//리소스 관리자 초기화
	if (!GET_SINGLE(ResManager)->Init(hdc))
	{
		return false;
	}
	
	// 체스말 관리자 초기화.
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