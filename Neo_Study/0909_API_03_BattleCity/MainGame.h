#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

class ResManager;
class EditorObject;

class MainGame
{
private:
	static MainGame*		m_sThis;
	ResManager*				m_pResManager;
	EditorObject*			m_pSelectObject;
	EditorObject*           m_pObject[32][24];
	vector<EditorObject*>	m_vecFixedObject;
	vector<EditorObject*>	m_vecBlockContainer;
	HWND					m_hWnd;
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
	void Input(POINT pt);
	void OpenFile(HWND hWnd);
	void SaveFile(HWND hWnd);
	void Release();

	~MainGame();
};

