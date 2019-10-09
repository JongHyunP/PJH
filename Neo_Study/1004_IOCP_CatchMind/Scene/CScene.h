#pragma once
#include "..\\value.h"

class CScene
{
protected:
	friend class SceneManager;

protected:
	CScene();
	virtual ~CScene() = 0 ; //�߻�Ŭ����

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

//�θ�Ŭ������ �Ҹ��ڸ� �����Լ��� �ϴ�����?
//-> �ڽ��� �Ҹ��ڸ� ȣ���ϱ� ���� 