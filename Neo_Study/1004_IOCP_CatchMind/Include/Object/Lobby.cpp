#include "Lobby.h"
#include "../Resources/CTexture.h"

Lobby::Lobby()
{
}
Lobby::Lobby(const Lobby& lobby) :
	CStaticObj(lobby)
{

}

Lobby::~Lobby()
{
}

bool Lobby::Init()
{
	SetPos(100.f, 0.f);
	SetSize(1005.f, 720.f);
	SetPivot(0.0f, 0.0f);

	SetTexture("Lobby", L"Lobby.bmp");

	return true;
}

void Lobby::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

int Lobby::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);
	return 0;
}

int Lobby::LateUpdate(float fDeltaTime)
{
	CStaticObj::LateUpdate(fDeltaTime);
	return 0;
}

void Lobby::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);
}

void Lobby::Render(HDC hdc, float fDeltaTime)
{
	//CStaticObj::Render(hdc,fDeltaTime);

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

Lobby * Lobby::Clone()
{
	return new Lobby(*this);
}
