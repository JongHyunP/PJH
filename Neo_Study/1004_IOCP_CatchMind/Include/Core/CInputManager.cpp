#include "CInputManager.h"
#include  "../Object/CMouse.h"
#include "../Scene/CLayer.h"
#include "../Collider/CColliderManager.h"

DEFINITION_SINGLE(CInputManager)

CInputManager::CInputManager() : m_pCreateKey(NULL), m_pMouse(NULL)
{

}

CInputManager::~CInputManager()
{
	CObj::EraseObj(m_pMouse);
	SAFE_RELEASE(m_pMouse);
	Safe_Delete_Map(m_mapKey);
}

bool CInputManager::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	AddKey(VK_RETURN, "Enter");
	AddKey(VK_LBUTTON, "MouseLButton");
	//마우스 위치
	GetCursorPos(&m_tMousePos);

	//마우스 생성 
	m_pMouse = CObj::CreateObj<CMouse>("Mouse");
	m_pMouse->SetSize(32, 32);
	//m_pMouse->SetTexture("Mouse", L"mouse.bmp");


	return true;
}

void CInputManager::Update(float fDeltaTime)
{
	unordered_map<string, PKEYINFO>::iterator iter;
	unordered_map<string, PKEYINFO>::iterator iterEnd = m_mapKey.end();

	for (iter = m_mapKey.begin(); iter != iterEnd; ++iter)
	{
		int iPushCount = 0;
		for (size_t i = 0; i < iter->second->vecKey.size(); ++i)
		{
			if (GetAsyncKeyState(iter->second->vecKey[i]) & 0x8000)
			{
				++iPushCount;
			}
		}

		if (iPushCount == iter->second->vecKey.size())
		{
			if (!iter->second->bDown && !iter->second->bPress)
			{
				iter->second->bPress = true;
				iter->second->bDown = true;
			}
			else if (iter->second->bDown)
			{
				iter->second->bDown = false;
			}
		}
		else
		{
			if (iter->second->bDown || iter->second->bPress)
			{
				iter->second->bUp = true;
				iter->second->bPress = false;
				iter->second->bDown = false;
			}
			else if (iter->second->bUp)
			{
				iter->second->bUp = false;
			}
		}
	}
	m_pMouse->Update(fDeltaTime);
	m_pMouse->LateUpdate(fDeltaTime);
	GET_SINGLE(CColliderManager)->AddObject(m_pMouse);
}

bool CInputManager::KeyDown(const string& strKey) const
{
	PKEYINFO pInfo = FindKey(strKey);

	if (!pInfo)
	{
		return false;
	}

	return pInfo->bDown;
}

bool CInputManager::KeyPress(const string& strKey) const
{
	PKEYINFO pInfo = FindKey(strKey);

	if (!pInfo)
	{
		return false;
	}

	return pInfo->bPress;
}

bool CInputManager::KeyUp(const string& strKey) const
{
	PKEYINFO pInfo = FindKey(strKey);

	if (!pInfo)
	{
		return false;
	}

	return pInfo->bUp;
}

PKEYINFO CInputManager::FindKey(const string& strKey) const
{
	unordered_map<string, PKEYINFO>::const_iterator iter = m_mapKey.find(strKey);

	if (iter == m_mapKey.end())
	{
		return NULL;
	}

	return iter->second;
}
