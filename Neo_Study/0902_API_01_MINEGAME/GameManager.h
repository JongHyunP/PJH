#pragma once
#include <Windows.h>
#include <memory>
#include <vector>

using namespace std;

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_SHOW,
	GAME_STATE_OVER
};

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
	GAME_STATE				m_eState;
	Mine*					m_pSelectMine;
	MineMap*				m_pSelectMineMap;
	int						m_level;
	DWORD					m_dwTimeCount;
	int						*MineRandomArray;
	int						m_iCount;
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
	void InputLeftButton(POINT pt);
	void InputRightButton(POINT pt);
	void OptionMapDraw(HDC hdc); //옵션 바뀌었을 때
	void FindMineNeighborhood(int count, int vectorCount);
	void Release();

	~GameManager();
};

