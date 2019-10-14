#include "CUIPanel.h"
#include "../Core/CInputManager.h"


CUIPanel::CUIPanel()
{
}

CUIPanel::CUIPanel(const CUIPanel& ui) : CUI(ui)
{

}

CUIPanel::~CUIPanel()
{

}

bool CUIPanel::Init()
{
	return true;
}

void CUIPanel::Input(float fDeltaTime)
{
	//CUI::Input(fDeltaTime);
	if (KEYDOWN("Enter"))
	{
		MessageBox(NULL, L"로그인중", L"로그인중", MB_OK);
	}
}

int CUIPanel::Update(float fDeltaTime)
{
	CUI::Update(fDeltaTime);
	return 0;
}

int CUIPanel::LateUpdate(float fDeltaTime)
{
	CUI::LateUpdate(fDeltaTime);
	return 0;
}

void CUIPanel::Collision(float fDeltaTime)
{
	CUI::Collision(fDeltaTime);
}

void CUIPanel::Render(HDC hdc, float fDeltaTime)
{
	CUI::Render(hdc,fDeltaTime);
}

CUIPanel * CUIPanel::Clone()
{
	return new CUIPanel(*this);
}
