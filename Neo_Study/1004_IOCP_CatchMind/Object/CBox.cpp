#include "CBox.h"



CBox::CBox()
{
}

CBox::CBox(const CBox& box) : CStaticObj(box)
{
	
}
CBox::~CBox()
{
}

bool CBox::Init()
{
	SetPos(100.f, 100.f);
	SetSize(100.f, 100.f);

	return true;
}

void CBox::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

int CBox::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);
	return 0;
}

int CBox::LateUpdate(float fDeltaTime)
{
	CStaticObj::LateUpdate(fDeltaTime);
	return 0;
}

void CBox::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);
}

void CBox::Render(HDC hdc, float fDeltaTime)
{
	CStaticObj::Render(hdc,fDeltaTime);
	Rectangle(hdc, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CBox * CBox::Clone()
{
	return new CBox(*this);
}
