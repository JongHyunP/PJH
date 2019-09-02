#pragma once
#include <Windows.h>
#include <memory>
#include <vector>

using namespace std;

class ResManager;
class Mine;
class MineMap;

class GameManager
{
private:
	static GameManager*		m_sThis;
	vector<Mine*>			m_vecMine;
	vector<MineMap*>		m_vecMineMap;
	ResManager*				m_pResManager;
	HWND					m_hWnd;
	Mine*					m_pSelectMine;
	MineMap*				m_pSelectMineMap;
	int						m_level;
	GameManager();
public:
	static GameManager* GetInstance()
	{
		if (m_sThis == nullptr)
			m_sThis = new GameManager();

		return m_sThis;
	}

	void Init(HWND hWnd, HDC hdc, HINSTANCE hInst);
	void Draw(HDC hdc);
	void Update();
	void Input(POINT pt);
	void OptionMapDraw(HDC hdc); //옵션 바뀌었을 때

	void Release();

	~GameManager();
};

