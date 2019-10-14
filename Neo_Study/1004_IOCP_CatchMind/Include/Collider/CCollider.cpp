#include "CCollider.h"
#include "../Object/CObj.h"

CCollider::CCollider()
{
}

CCollider::CCollider(const CCollider& coll)
{
	*this = coll;
}

CCollider::~CCollider()
{
	list<CCollider*>::iterator iter;
	list<CCollider*>::iterator iterEnd = m_CollisionList.end();

	for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
	{
		//내가 가지고있는 목록에서 자신을 지워달라고 요청해야함.
		(*iter)->EraseCollisionList(this);
	}
}

void CCollider::Input(float fDeltaTime)
{
}

int CCollider::Update(float fDeltaTime)
{
	return 0;
}

int CCollider::LateUpdate(float fDeltaTime)
{
	return 0;
}

bool CCollider::Collision(CCollider* pDest)
{
	return false;
}

void CCollider::Render(HDC hdc, float fDeltaTime)
{
}

bool CCollider::CollisionRectToRect(const RECTANGLE& src, const RECTANGLE& dest)
{
	if (src.left > dest.right)
	{
		return false;
	}
	else if (src.right < dest.left)
	{
		return false;
	}
	else if (src.top > dest.botton)
	{
		return false;
	}
	else if (src.botton < dest.top)
	{
		return false;
	}

	return true;
}

bool CCollider::CollisionRectToPoint(const RECTANGLE & src, const POSITION & dest)
{
	if (dest.x < src.left)
	{
		return false;
	}
	else if (dest.x > src.right)
	{
		return false;
	}
	else if (dest.y < src.top)
	{
		return false;
	}
	else if (dest.y > src.botton)
	{
		return false;
	}

	return true;


	return false;
}
