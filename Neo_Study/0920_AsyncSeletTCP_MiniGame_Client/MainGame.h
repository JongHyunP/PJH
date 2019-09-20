#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

class BoardTile;
class ResManager;


class MainGame
{
private:
	static MainGame* m_sThis;
	ResManager* m_pResManager;
	BoardTile* m_pBoard[8][8];
	vector<BoardTile*> m_vecBoardTile;
	//Player* m_pPlayer;
	MainGame();

public:
	static MainGame* GetInstance()
	{
		if (m_sThis == nullptr)
			m_sThis = new MainGame();

		return m_sThis;
	}

	void Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Update();
	void Release();

	~MainGame();
};

