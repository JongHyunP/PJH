#include "CLayer.h"
#include "..\\Object\CObj.h"

CLayer::CLayer() : 
	m_iZOrder(0),
	m_strTag(""),
	m_pScene(NULL), 
	m_bLayerEnable(true),
	m_bLayerLife(true)
{

}

CLayer::~CLayer()
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		CObj::EraseObj(*iter);
		SAFE_RELEASE((*iter));
	}
	
	m_ObjList.clear();
}

void CLayer::AddObject(CObj * pObj)
{
	pObj->SetScene(m_pScene);
	pObj->SetLayer(this);
	pObj->AddRef();

	m_ObjList.push_back(pObj);
}

void CLayer::Input(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
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
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}

int CLayer::Update(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
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
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}

	return 0;
}

int CLayer::LateUpdate(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
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
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
	return 0;
}

void CLayer::Collision(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
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
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}

void CLayer::Render(HDC hdc, float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
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
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}
