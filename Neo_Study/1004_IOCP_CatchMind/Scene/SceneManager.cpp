#include "SceneManager.h"
#include "CInGameScene.h"

DEFINITION_SINGLE(SceneManager)

SceneManager::SceneManager() : m_pScene(NULL), m_pNextScene(NULL)
{

}
SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pScene);
}

bool SceneManager::Init()
{
	CreateScene<CInGameScene>(SC_CURRENT);
	return true;
}

void SceneManager::Input(float fDeltaTime)
{
	m_pScene->Input(fDeltaTime);
}

int SceneManager::Update(float fDeltaTime)
{
	m_pScene->Update(fDeltaTime);
	return 0;
}

int SceneManager::LateUpdate(float fDeltaTime)
{
	m_pScene->LateUpdate(fDeltaTime);
	return 0;
}

void SceneManager::Collision(float fDeltaTime)
{
	m_pScene->Collision(fDeltaTime);
}

void SceneManager::Render(HDC hdc, float fDeltaTime)
{
	m_pScene->Render(hdc,fDeltaTime);
}

