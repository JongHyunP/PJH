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
	EditorObject*			m_pUndoObject;
	EditorObject*           m_pObject[32][24];
	vector<EditorObject*>	m_vecFixedObject;
	vector<EditorObject*>	m_vecBlockReDoContainer;
	vector<EditorObject*>	m_vecBlockUnDoContainer;
	HWND					m_hWnd;
	OPENFILENAME			OFN;
	char					IpstrFile[MAX_PATH] = "";
	char					str[256];
	int						m_iChoiceBlockNum;
	bool					m_bClickInMap; //¸Ê¾È¿¡ Âï´ÂÁö Ã¼Å©
	MainGame();
public:
	static MainGame* GetInstance()
	{
		if (m_sThis == nullptr)
			m_sThis = new MainGame();

		return m_sThis;
	}

	void Init(HWND hWnd, HDC hdc, HINSTANCE g_hInst);
	void Draw(HDC hdc);
	void Update();
	void KeyBoardInput(int virtualKey);
	void MouseInput(POINT pt);
	void OpenFile(HWND hWnd);
	void SaveFile(HWND hWnd);
	void Redo(EditorObject* iter);
	void Undo(EditorObject* iter);
	void ChangeObject(EditorObject* obj, EditorObject* iter,int num);
	void RadioCommand(HWND hWnd,WPARAM wParam);
	void Release();

	~MainGame();
};

