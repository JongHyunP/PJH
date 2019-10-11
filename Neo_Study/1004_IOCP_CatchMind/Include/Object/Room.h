#pragma once
#include "CStaticObj.h"

class Room:
	public CStaticObj
{
private:
	friend class CObj;
	friend class CScene;
private:
	Room();
	Room(const Room& room);
	~Room();

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual Room* Clone();
};

