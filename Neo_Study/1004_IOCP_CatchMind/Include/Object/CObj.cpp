#include "CObj.h"
#include "..\Scene\CLayer.h"
#include "../Scene/CScene.h"
#include "../Scene/SceneManager.h"
#include "../Resources/CResourceManager.h"
#include "../Resources/CTexture.h"

list<CObj*> CObj::m_ObjectList;
unordered_map<string, CObj*> CObj::m_mapPrototype;

CObj::CObj() :m_pTexture(NULL)
{

}

CObj::CObj(const CObj & obj)
{
	*this = obj;

	//기존에 복사 해주는 객체가 텍스쳐를 가지고있다면 공유 
	if (m_pTexture)
	{
		m_pTexture->AddRef();
	}
}

CObj::~CObj()
{
	// 삭제시 레퍼런스 카운터 감소
	SAFE_RELEASE(m_pTexture);
}

void CObj::AddObj(CObj * pObj)
{
	pObj->AddRef(); //레퍼런스 카운트 추가

	m_ObjectList.push_back(pObj);
}

CObj * CObj::FindObject(const string & strTag)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjectList.end();

	for (iter = m_ObjectList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			(*iter)->AddRef();
			return *iter;
		}
	}

	return NULL;
}

void CObj::EraseObj(CObj * pObj)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjectList.end();

	for (iter = m_ObjectList.begin(); iter != iterEnd; ++iter)
	{
		if (*iter==pObj)
		{
			SAFE_RELEASE((*iter));
			iter = m_ObjectList.erase(iter);
			return;
		}
	}
}

void CObj::EraseObj(const string & strTag)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjectList.end();

	for (iter = m_ObjectList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			SAFE_RELEASE((*iter));
			iter = m_ObjectList.erase(iter);
			return;
		}
	}
}

void CObj::EraseObj()
{
	Safe_Release_VecList(m_ObjectList);
}

void CObj::ErasePrototype(const string & strTag)
{
	unordered_map<string, CObj*>::iterator iter;
	iter = m_mapPrototype.find(strTag);

	if (!iter->second)
	{
		return;
	}

	SAFE_RELEASE(iter->second);
	m_mapPrototype.erase(iter);
}

void CObj::ErasePrototype()
{
	Safe_Release_Map(m_mapPrototype);
}

void CObj::SetTexture(CTexture* pTexture)
{
	//기존 텍스쳐 날리고
	SAFE_RELEASE(m_pTexture);
	m_pTexture = pTexture;

	if (pTexture)
	{ //null이 아닐떄만 카운터 추가해주기
		pTexture->AddRef();
	}
}

void CObj::SetTexture(const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	SAFE_RELEASE(m_pTexture);

	m_pTexture = GET_SINGLE(CResourceManager)->LoadTexture(
		strKey, pFileName, strPathKey);
}

void CObj::Input(float fDeltaTime)
{
}

int CObj::Update(float fDeltaTime)
{
	return 0;
}

int CObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CObj::Collision(float fDeltaTime)
{
}

void CObj::Render(HDC hdc, float fDeltaTime)
{
	if (m_pTexture)
	{
		POSITION tPos = m_tPos - m_tSize * m_tPivot;

		BitBlt(hdc, tPos.x, tPos.y, m_tSize.x, m_tSize.y, m_pTexture->GetDC(), 0, 0, SRCCOPY);
	}
}

CObj * CObj::CreateCloneObj(const string & strPrototypeKey, const string & strTag,
	class CLayer* pLayer)
{
	CObj* pProto = FindPrototype(strPrototypeKey);

	if (!pProto)
	{
		return NULL;
	}
	CObj * pObj = pProto->Clone();

	pObj->SetTag(strTag);

	if (pLayer)
	{
		pLayer->AddObject(pObj);
	}

	AddObj(pObj);

	return pObj;
}

CObj * CObj::FindPrototype(const string & strKey)
{
	unordered_map<string, CObj*>::iterator iter;
	iter = m_mapPrototype.find(strKey);

	if (iter == m_mapPrototype.end())
	{
		return NULL;
	}

	return iter->second;
}
