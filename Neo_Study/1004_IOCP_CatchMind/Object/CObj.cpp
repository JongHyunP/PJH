#include "CObj.h"

CObj::CObj() : m_iRef(1) //ó�������� 1
{

}

CObj::~CObj()
{
}

bool CObj::Init()
{
	return true;
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
}
