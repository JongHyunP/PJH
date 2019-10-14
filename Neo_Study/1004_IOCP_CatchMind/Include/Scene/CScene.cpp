#include "CScene.h"
#include "CLayer.h"

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("UI", INT_MAX);
	pLayer = CreateLayer("HUD", INT_MAX-1);
	pLayer = CreateLayer("Default",1);
	pLayer = CreateLayer("Room",2);

	m_eSceneType = SC_CURRENT;
}

CScene::~CScene()
{
	//할당된 레이어를 전부 클리어
	Safe_Delete_VecList(m_LayerList);
}

CLayer* CScene::CreateLayer(const string& strTag, int iZOrder)
{
	CLayer* pLayer = new CLayer;

	pLayer->SetTag(strTag);
	pLayer->SetOrder(iZOrder);
	pLayer->SetScene(this);

	m_LayerList.push_back(pLayer);

	if (m_LayerList.size() >= 2)
		m_LayerList.sort(CScene::LayerSort);

	return pLayer;
}

CLayer * CScene::FindLayer(const string & strTag)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			return *iter;
		}
	}

	return NULL;
}

bool CScene::LayerSort(CLayer* pL1, CLayer* pL2)
{
	return pL1->GetZOder() < pL2->GetZOder();
}

bool CScene::Init()
{
	return true;
}

void CScene::Input(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //레이어가 비활성화이면
		{
			++iter; //해당 레이어는 무시
			continue; 
		}
		//활성화면 그대로 출력
		(*iter)->Input(fDeltaTime);
		
		//삭제시
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
}

int CScene::Update(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //레이어가 비활성화이면
		{
			++iter; //해당 레이어는 무시
			continue;
		}
		//활성화면 그대로 출력
		(*iter)->Update(fDeltaTime);

		//삭제시
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}

	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //레이어가 비활성화이면
		{
			++iter; //해당 레이어는 무시
			continue;
		}
		//활성화면 그대로 출력
		(*iter)->LateUpdate(fDeltaTime);

		//삭제시
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}

	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //레이어가 비활성화이면
		{
			++iter; //해당 레이어는 무시
			continue;
		}
		//활성화면 그대로 출력
		(*iter)->Collision(fDeltaTime);

		//삭제시
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
}

void CScene::Render(HDC hdc, float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //레이어가 비활성화이면
		{
			++iter; //해당 레이어는 무시
			continue;
		}
		//활성화면 그대로 출력
		(*iter)->Render(hdc,fDeltaTime);

		//삭제시
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
}
