#include "CColliderManager.h"
#include "../Object/CObj.h"
#include "CCollider.h"

DEFINITION_SINGLE(CColliderManager)

CColliderManager::CColliderManager()
{

}

CColliderManager::~CColliderManager()
{

}

void CColliderManager::AddObject(CObj* pObj)
{
	//충돌체를 가지고있을때
	if (pObj->CheckCollider())
	{
		m_ColliderList.push_back(pObj);
	}

}

void CColliderManager::Collision(float fDeltaTime)
{
	if (m_ColliderList.size() < 2) //충돌체 두개
	{
		m_ColliderList.clear(); //매 프레임마다 클리어
		return;
	}

	//오브젝트간 충돌처리
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ColliderList.end();
	--iterEnd;

	for (iter = m_ColliderList.begin(); iter != iterEnd; ++iter)
	{
		list<CObj*>::iterator iter2 = iter;
		++iter2;
		list<CObj*>::iterator iter2End = m_ColliderList.end();
		for (; iter2 != iter2End; ++iter2)
		{
			Collision(*iter, *iter2, fDeltaTime);
		}
	}


	m_ColliderList.clear();
}

//서로 충돌처리
bool CColliderManager::Collision(CObj* pSrc, CObj* pDest, float fDeltaTime)
{
	const list<CCollider*>* pSrcList = pSrc->GetColliderList();
	const list<CCollider*>* pDestList = pDest->GetColliderList();

	list<CCollider*>::const_iterator iterSrc;
	list<CCollider*>::const_iterator iterSrcEnd = pSrcList->end();

	list<CCollider*>::const_iterator iterDest;
	list<CCollider*>::const_iterator iterDestEnd = pDestList->end();

	bool bCollision = false;

	for (iterSrc = pSrcList->begin(); iterSrc != iterSrcEnd; ++iterSrc)
	{
		for (iterDest = pDestList->begin(); iterDest != iterDestEnd; ++iterDest)
		{
			if ((*iterSrc)->Collision(*iterDest))
			{
				bCollision = true;

				//처음 충돌목록에서 이전에 충돌된적이 없다면 처음충돌.
				if (!(*iterSrc)->CheckCollisionList(*iterDest))
				{
					//서로 상대방 충돌목록으로 추가
					(*iterSrc)->AddCollider(*iterDest);
					(*iterDest)->AddCollider(*iterSrc);

					(*iterSrc)->CallFunction(CS_ENTER,*iterDest,fDeltaTime);
					(*iterDest)->CallFunction(CS_ENTER ,*iterSrc, fDeltaTime);
				}
				else //기존 충돌된적이있다면 계속 충돌상태.
				{
					(*iterSrc)->CallFunction(CS_STAY, *iterDest, fDeltaTime);
					(*iterDest)->CallFunction(CS_STAY, *iterSrc, fDeltaTime);
				}
			}
			//현재 충돌이 안된 상태에서 이전에 충돌이 되고있었다면
			//이제 막 충돌 상태에서 떨어졌다는 의미.
			else if((*iterSrc)->CheckCollisionList(*iterDest))
			{
				//서로 충돌이 안되므로 충돌목록에서 지워줌.
				(*iterSrc)->EraseCollisionList(*iterDest);
				(*iterDest)->EraseCollisionList(*iterSrc);

				(*iterSrc)->CallFunction(CS_LEAVE, *iterDest, fDeltaTime);
				(*iterDest)->CallFunction(CS_LEAVE, *iterSrc, fDeltaTime);
			}
		}
	}
	return bCollision;
}
