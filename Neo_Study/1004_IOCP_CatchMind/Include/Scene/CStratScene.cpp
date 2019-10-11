#include "CStratScene.h"
#include "CLayer.h"
#include "../Object/CUIPanel.h"
#include "../Core/CCore.h"


CStratScene::CStratScene()
{
}


CStratScene::~CStratScene()
{
}

bool CStratScene::Init()
{
	// 부모 씬 클래스의 초기화 함수를 호출
	if (!CScene::Init())
	{
		return false;
	}

	//스타트 씬에서 보여줄것들.

	CLayer* pLayer = FindLayer("UI");
	CUIPanel* pBackPanel = CObj::CreateObj<CUIPanel>("BackPanel", pLayer);

	pBackPanel->SetSize(GETREOULUTION.iW, GETREOULUTION.iH);
	pBackPanel->SetTexture("LoginBack", L"BackGround.bmp");
	SAFE_RELEASE(pBackPanel);

	return true;
}
