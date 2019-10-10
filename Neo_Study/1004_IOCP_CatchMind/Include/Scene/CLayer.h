#pragma once

#include "..\\value.h"

class CLayer
{
private:
	friend class CScene;

private:
	CLayer();
public:
	~CLayer();
private:
	class CScene*		m_pScene;
	string				m_strTag;
	int					m_iZOrder;
	list<class CObj*>	m_ObjList;
	bool				m_bLayerEnable;
	bool				m_bLayerLife;

public:
	void SetTag(const string& strTag)
	{
		m_strTag = strTag;
	}
	void SetOrder(int iZOrder)
	{
		m_iZOrder = iZOrder;
	}
	void SetScene(class CScene* pScene)
	{
		m_pScene = pScene;
	}
	int GetZOder() const
	{
		return m_iZOrder;
	}
	string GetTag() const
	{
		return m_strTag;
	}
	CScene* GetScene() const
	{
		return m_pScene;
	}

public:
	void SetEnable(bool bEnable)
	{
		m_bLayerEnable = bEnable;
	}
	void Die()
	{
		m_bLayerLife = false;
	}
	bool GetEnable() const
	{
		return m_bLayerEnable;
	}
	bool GetLife() const
	{
		return m_bLayerLife;
	}
public:
	void AddObject(class CObj* pObj);

public:
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hdc, float fDeltaTime);
};

