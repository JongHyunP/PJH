#pragma once
#include "value.h"

class Scene
{
protected:
	friend class SceneManager; //부모에도 접근가능하도록

protected:
	Scene();
	virtual ~Scene() = 0;
	
protected:
	list<class Layer*> m_LayerList;

public:
	virtual bool Init();

	class Layer* CreateLayer
};

