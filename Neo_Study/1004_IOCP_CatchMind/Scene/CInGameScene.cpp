#include "CInGameScene.h"
#include "CLayer.h"
#include "..\Object\CBox.h"

CInGameScene::CInGameScene()
{

}
CInGameScene::~CInGameScene()
{
}

bool CInGameScene::Init()
{
	// 부모 씬 클래스의 초기화 함수를 호출
	if (!CScene::Init())
	{
		return false;
	}

	CLayer* pLayer = FindLayer("Default");

	CBox* pBox = CObj::CreateObj<CBox>("Box", pLayer);

	SAFE_RELEASE(pBox);  //오브젝트를 레이어만 가지고 있으니 릴리즈 해줌

	return true;
}
