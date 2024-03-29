#pragma once
#include "..\\value.h"

class CScene
{
protected:
	friend class SceneManager;

protected:
	CScene();
	virtual ~CScene() = 0 ; //추상클래스

protected:
	list<class CLayer*>		m_LayerList;
	SCENE_CREATE			m_eSceneType;
public:
	void SetSceneType(SCENE_CREATE eType)
	{
		m_eSceneType = eType;
	}
	SCENE_CREATE GetSceneType() const
	{
		return m_eSceneType;
	}
public:
	class CLayer* CreateLayer(const string& strTag, int iZOrder =0);
	class CLayer* FindLayer(const string& strTag);
public:
	static bool LayerSort(CLayer* pL1, CLayer* pL2);

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc,float fDeltaTime);
};
