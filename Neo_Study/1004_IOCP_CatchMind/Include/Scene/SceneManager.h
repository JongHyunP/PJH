#pragma once
#include "..\\value.h"

class SceneManager
{
	DECLARE_SINGLE(SceneManager)

private:
	class CScene* m_pScene;
	class CScene* m_pNextScene;

public:
	bool Init();
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hdc, float fDeltaTime);

public:
	template <typename T>
	T* CreateScene(SCENE_CREATE sc)
	{
		T* pScene = new T;
		if (!pScene->Init())
		{
			SAFE_DELETE(pScene);
			return NULL;
		}
		
		switch (sc)
		{
		case SC_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SC_NEXT:
			SAFE_DELETE(m_pNextScene);
			m_pNextScene = pScene;
			break;
		}

		return pScene;
	}
};

