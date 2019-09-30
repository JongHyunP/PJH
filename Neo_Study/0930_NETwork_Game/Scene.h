#pragma once
#include "value.h"

class Scene
{
protected:
	friend class SceneManager; //�θ𿡵� ���ٰ����ϵ���

protected:
	Scene();
	virtual ~Scene() = 0;
	
protected:
	list<class Layer*> m_LayerList;

public:
	virtual bool Init();

	class Layer* CreateLayer
};

