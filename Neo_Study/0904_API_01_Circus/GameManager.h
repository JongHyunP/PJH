#pragma once
#include <Windows.h>
#include <memory>
#include <vector>

using namespace std;

class ResManager;
class Object;

class GameManager
{
private:
	static GameManager*		m_sThis;
	ResManager*				m_pResManager;
	//vector<Object*>			m_vecUi;
	//vector<Object*>			m_vecBackground;
	//vector<Object*>			m_vecPlayer;

	HWND					m_hWnd;
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
	void InputKeyBoard(WPARAM wParam, HWND hWnd);
	void Update();
	void Release();

	~GameManager();
};

