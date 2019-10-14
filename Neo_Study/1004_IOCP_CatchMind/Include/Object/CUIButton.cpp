#include "CUIButton.h"
#include "../Collider/CColliderRect.h"
#include "../Collider/CCollider.h"
#include "../Core/CInputManager.h"

CUIButton::CUIButton() :m_bEnableCallback(false), m_eState(BS_NONE)
{

}

CUIButton::CUIButton(const CUIButton& ui) : CUI(ui)
{
	m_bEnableCallback = false;
	m_eState = BS_NONE;
}

CUIButton::~CUIButton()
{

}

bool CUIButton::Init()
{
	CColliderRect* pColl = AddCollider<CColliderRect>("ButtonBody");

	SAFE_RELEASE(pColl);

	return true;
}

void CUIButton::Input(float fDeltaTime)
{
	CUI::Input(fDeltaTime);
}

int CUIButton::Update(float fDeltaTime)
{
	CUI::Update(fDeltaTime);
	return 0;
}

int CUIButton::LateUpdate(float fDeltaTime)
{
	CUI::LateUpdate(fDeltaTime);
	//L��ư Ŭ���� �ߴ��� ���ߴ���
	if (m_eState != BS_NONE)
	{
		if (KEYPRESS("MouseLButton"))
		{
			m_eState = BS_CLICK;
		}
	}
	if (m_eState == BS_CLICK && KEYUP("MouseLButton")) //Ŭ���ϰ� �� ��
	{
		if (m_bEnableCallback)
		{
			m_BtnCallback(fDeltaTime);
		}
	}
	return 0;
}

void CUIButton::Collision(float fDeltaTime)
{
	CUI::Collision(fDeltaTime);
}

void CUIButton::Render(HDC hdc, float fDeltaTime)
{
	CUI::Render(hdc,fDeltaTime);
}

CUIButton* CUIButton::Clone()
{
	return new CUIButton(*this);
}

void CUIButton::MouseOn(CCollider * pSrc, CCollider * pDest, float fDeltaTime)
{
	if (pDest->GetTag() == "Mouse")
	{
		m_eState = BS_MOUSEON;
	}
}

void CUIButton::MouseOut(CCollider * pSrc, CCollider * pDest, float fDeltaTime)
{
	if (pDest->GetTag() == "Mouse")
	{
		m_eState = BS_NONE;
	}
}
