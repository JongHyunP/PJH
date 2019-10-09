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
	list<class CLayer*> m_LayerList;

public:
	class CLayer* CreateLayer(const string& strTag, int iZOrder =0);

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

//부모클래스의 소멸자를 가상함수로 하는이유?
//-> 자식의 소멸자를 호출하기 위해 