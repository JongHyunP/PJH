#include "Scene.h"
#include "Layer.h"


Scene::Scene()
{
}


Scene::~Scene()
{
	Safe_Delete_VecList(m_LayerList);
}

bool Scene::Init()
{

	return true;
}
