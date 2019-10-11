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
	SetPos(0.f, 0.f);
	SetSize(1280.f, 720.f);
	SetPivot(0.0f, 0.0f);

	SetTexture("Box", L"BackGround.bmp");

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
}

CBox * CBox::Clone()
{
	return new CBox(*this);
}
