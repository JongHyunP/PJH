#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

class ResManager;

class MainGame
{
private:
	static MainGame*		m_sThis;
	ResManager*				m_pResManager;
	OPENFILENAME			OFN;
	char					IpstrFile[MAX_PATH] = "";
	char					str[256];
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
	void Input(int virtualKey, bool iskeydown);
	void OpenFile(HWND hWnd);
	void SaveFile(HWND hWnd);
	void Release();

	~MainGame();
};

