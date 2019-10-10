#pragma once
#include "CStaticObj.h"
class CBox :
	public CStaticObj
{
private:
	friend class CObj;
private:
	CBox();
	CBox(const CBox& box);
	~CBox();
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CBox* Clone();
};

