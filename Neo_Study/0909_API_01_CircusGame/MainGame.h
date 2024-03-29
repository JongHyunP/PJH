#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

class BackTile;
class ResManager;
class Player;
class Camera;

class MainGame
{
private:
	static MainGame* m_sThis;
	ResManager* m_pResManager;
	vector<BackTile*> m_vecTile;
	Player* m_pPlayer;
	Camera* m_pCamera;
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
	void Input(int virtualKey,bool iskeydown);
	void Release();
	
	~MainGame();
};

