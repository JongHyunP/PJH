#pragma once
#include "CCollider.h"
class CColliderRect :
	public CCollider
{
protected:
	friend class CObj;

protected:
	CColliderRect();
	CColliderRect(const CColliderRect& coll);
	virtual ~CColliderRect();

private:
	RECTANGLE	m_tInfo;
	RECTANGLE	m_tWorldInfo; //월드 좌표 기준

public:
	void SetRect(float left, float top, float right, float botton);
	RECTANGLE GetInfo() const
	{
		return m_tInfo;
	}
	RECTANGLE GetWorldInfo() const
	{
		return m_tWorldInfo;
	}
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual bool Collision(CCollider* pDest);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CColliderRect* Clone();
};

