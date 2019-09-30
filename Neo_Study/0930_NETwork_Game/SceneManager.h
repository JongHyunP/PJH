#pragma once
#include "value.h"

enum SCENE_TYPE
{
	ST_LOBBY,
	ST_INGAME
};

enum SCENE_CREATE
{
	SC_CURRENT,
	SC_NEXT
};


class SceneManager
{
private:
	class Scene* m_pScene;
	class Scene* m_pNextScene;
public:
	bool Init();
	
public:
	template<typename T>
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
		default:
			break;
		}

		return pScene;
	}

	DECLARE_SINGLE(SceneManager)
};

