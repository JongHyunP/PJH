#include "Room.h"
#include "../Resources/CTexture.h"
#include "../Core/CCore.h"

Room::Room()
{

}

Room::Room(const Room& room) :
	CStaticObj(room)
{

}

Room::~Room()
{
}


bool Room::Init()
{
	SetPos(100.f, 0.f);
	SetSize(1005.f, 720.f);
	SetPivot(0.0f, 0.0f);

	SetTexture("Room", L"Room.bmp");

	return true;
}

void Room::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

int Room::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);
	return 0;
}

int Room::LateUpdate(float fDeltaTime)
{
	CStaticObj::LateUpdate(fDeltaTime);
	return 0;
}

void Room::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);
}

void Room::Render(HDC hdc, float fDeltaTime)
{
	//CStaticObj::Render(hdc, fDeltaTime);
	if (m_pTexture)
	{
		POSITION tPos = m_tPos - m_tSize * m_tPivot;

		BitBlt(hdc, tPos.x, tPos.y, GETREOULUTION.iW, GETREOULUTION.iH, m_pTexture->GetDC(), 0, 0, SRCCOPY);
	}
}

Room * Room::Clone()
{
	return new Room(*this);
}