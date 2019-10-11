#include "CInGameScene.h"
#include "CLayer.h"
#include "..\Object\CBox.h"
#include "..\Object\Room.h"
#include "../Object/Lobby.h"

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

	CLayer* pLayer = FindLayer("Default");

	CBox* pBox = CObj::CreateObj<CBox>("Box", pLayer);

	SAFE_RELEASE(pBox);  //������Ʈ�� ���̾ ������ ������ ������ ����

	CLayer* pRoomLayer = FindLayer("Room");

	Room* pRoom = CObj::CreateObj<Room>("Room", pRoomLayer);

	SAFE_RELEASE(pRoom);

	return true;
}
