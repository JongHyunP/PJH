#pragma once
#include "CStaticObj.h"

class Lobby :
	public CStaticObj
{
private:
	friend class CObj;
	friend class CScene;

private:
	Lobby();
	Lobby(const Lobby& lobby);
	~Lobby();

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual Lobby* Clone();
};

