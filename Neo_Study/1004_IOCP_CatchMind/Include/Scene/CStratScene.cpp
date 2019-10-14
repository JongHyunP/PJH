#include "CStratScene.h"
#include "CLayer.h"
#include "../Object/CUIPanel.h"
#include "../Object/CUIButton.h"
#include "../Core/CCore.h"
#include "SceneManager.h"
#include "CInGameScene.h"
#include "../Collider/CColliderRect.h"


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
	CUIPanel* pBackPanel = CObj::CreateObj<CUIPanel>("LoginPanel", pLayer);

	pBackPanel->SetSize(GETREOULUTION.iW, GETREOULUTION.iH);
	pBackPanel->SetTexture("LoginPanel", L"login.bmp");
	SAFE_RELEASE(pBackPanel);

	CUIButton* pStartBtn = CObj::CreateObj<CUIButton>("StartButton", pLayer);

	pStartBtn->SetPos(800, 500);
	pStartBtn->SetSize(155, 97);
	pStartBtn->SetTexture("StartButton", L"startbutton.bmp");

	CColliderRect* pRC = (CColliderRect*)pStartBtn->GetCollider("ButtonBody");

	POSITION tPos = pStartBtn->GetPosition();
	pRC->SetRect(0.f, 0.f, 155, 97);
	pRC->AddCollisionFunction(CS_ENTER, pStartBtn, &CUIButton::MouseOn);
	pRC->AddCollisionFunction(CS_LEAVE, pStartBtn, &CUIButton::MouseOut);


	SAFE_RELEASE(pRC);

	pStartBtn->SetCallback(this, &CStratScene::StartButtonCallback);

	SAFE_RELEASE(pStartBtn);

	return true;
}

void CStratScene::StartButtonCallback(float fTime)
{
	GET_SINGLE(SceneManager)->CreateScene<CInGameScene>(SC_NEXT);
}
