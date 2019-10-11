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
	// �θ� �� Ŭ������ �ʱ�ȭ �Լ��� ȣ��
	if (!CScene::Init())
	{
		return false;
	}

	//��ŸƮ ������ �����ٰ͵�.

	CLayer* pLayer = FindLayer("UI");
	CUIPanel* pBackPanel = CObj::CreateObj<CUIPanel>("BackPanel", pLayer);

	pBackPanel->SetSize(GETREOULUTION.iW, GETREOULUTION.iH);
	pBackPanel->SetTexture("LoginBack", L"BackGround.bmp");
	SAFE_RELEASE(pBackPanel);

	return true;
}
