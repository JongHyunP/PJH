#include "CInGameScene.h"

CInGameScene::CInGameScene()
{

}
CInGameScene::~CInGameScene()
{
}

bool CInGameScene::Init()
{
	// �θ� �� Ŭ������ �ʱ�ȭ �Լ��� ȣ��
	if (!CScene::Init())
	{
		return false;
	}

	return true;
}
