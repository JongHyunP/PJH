#pragma once
#include "Input.h"
#include "SceneManager.h"

class SingletonGameManager
{
private:
	static SingletonGameManager* sGameManager;
	Input *pInput;
	SceneManager* sceneManager;

	SingletonGameManager() {
		
	}

public:
	static SingletonGameManager* getInstance() {
		
		if (sGameManager == nullptr)
		{
			sGameManager = new SingletonGameManager();
		}
		return sGameManager;

	}

	void Update();

	void Render(HDC hdc, float a);


	void Input(WPARAM wParam);

	void keyDraw(HDC hdc);

	void Relese()
	{
		if(sGameManager)
		delete sGameManager;
	}

};