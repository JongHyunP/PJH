#include "SceneManager.h"



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::registerScene(const string & sceneName, Scene * scene)
{
	sceneContainer.insert(pair<string,Scene*>(sceneName, scene));
}

void SceneManager::reserveChangeScene(const string & sceneName)
{
	map<string, Scene*>::iterator iter;
	iter = sceneContainer.find(sceneName);
	
}

void SceneManager::Update(int sceneUpdatenum) //�Է� ������ �ٲ��ְ�
{
	switch (sceneUpdatenum)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

void SceneManager::Render(HDC hdc, float dt) // �׷��ش�.
{
	
}
