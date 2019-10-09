#pragma once
#include "value.h"

class Layer
{
private:
	friend class Scene;
private:
	Layer();
public:
	~Layer();
private:
	class Scene* m_pScene;
	string m_strTag;
	int m_iZOrder; 

public:
	void SetTag(const string& strTag)
	{
		m_strTag = strTag;
	}
	void SetOrder(int iZOrder)
	{
		m_iZOrder = iZOrder;
	}
	void SetScene(class Scene* pScene)
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
	Scene* GetScene() const
	{
		return m_pScene;
	}
};

