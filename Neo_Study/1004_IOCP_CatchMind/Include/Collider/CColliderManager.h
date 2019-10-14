#pragma once
#include "../value.h"

class CColliderManager
{
	DECLARE_SINGLE(CColliderManager)
private:
	list<class CObj*> m_ColliderList;

public:
	void AddObject(CObj* pObj);
	void Collision(float fDeltaTime);
	bool Collision(class CObj* pSrc, class CObj* pDest, float fDeltaTime);
};

