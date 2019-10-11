#include "CUI.h"
#include "../Resources/CTexture.h"


CUI::CUI()
{
}

CUI::CUI(const CUI & ui) : CObj(ui)
{
}


CUI::~CUI()
{
}

void CUI::Input(float fDeltaTime)
{
}

int CUI::Update(float fDeltaTime)
{
	return 0;
}

int CUI::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CUI::Collision(float fDeltaTime)
{
}

void CUI::Render(HDC hdc, float fDeltaTime)
{
	if (m_pTexture)
	{
		POSITION tPos = m_tPos - m_tSize * m_tPivot;

		if (m_pTexture->GetColorKeyEnable())
		{
			TransparentBlt(hdc, tPos.x, tPos.y, m_tSize.x, m_tSize.y, m_pTexture->GetDC(), 0, 0, m_tSize.x, m_tSize.y, m_pTexture->GetColorKey());
		}
		else
		{
			BitBlt(hdc, tPos.x, tPos.y, m_tSize.x, m_tSize.y, m_pTexture->GetDC(), 0, 0, SRCCOPY);
		}
	}
}
