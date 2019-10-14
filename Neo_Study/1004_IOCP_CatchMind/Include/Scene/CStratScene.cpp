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
	// �θ� �� Ŭ������ �ʱ�ȭ �Լ��� ȣ��
	if (!CScene::Init())
	{
		return false;
	}

	//��ŸƮ ������ �����ٰ͵�.

	CLayer* pLayer = FindLayer("UI");
	CUIPanel* pBackPanel = CObj::CreateObj<CUIPanel>("LoginPanel", pLayer);

	pBackPanel->SetSize(GETREOULUTION.iW, GETREOULUTION.iH);
	pBackPanel->SetTexture("LoginPanel", L"login.bmp");
	SAFE_RELEASE(pBackPanel);

	CUIButton* pStartBtn = CObj::CreateObj<CUIButton>("StartButton", pLayer);

	pStartBtn->SetPos(552, 472);
	pStartBtn->SetSize(62, 51);
	pStartBtn->SetTexture("StartButton", L"LoginButton.bmp");

	CColliderRect* pRC = (CColliderRect*)pStartBtn->GetCollider("ButtonBody");
	POSITION tPos = pStartBtn->GetPosition();
	pRC->SetRect(tPos.x, tPos.y, tPos.x + 61, tPos.y + 51);
	SAFE_RELEASE(pRC);
	SAFE_RELEASE(pStartBtn);

	return true;
}

void CStratScene::StartButtonCallback(float fTime)
{
	GET_SINGLE(SceneManager)->CreateScene<CInGameScene>(SC_NEXT);
}
