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
	//�浹ü�� ������������
	if (pObj->CheckCollider())
	{
		m_ColliderList.push_back(pObj);
	}

}

void CColliderManager::Collision(float fDeltaTime)
{
	if (m_ColliderList.size() < 2) //�浹ü �ΰ�
	{
		m_ColliderList.clear(); //�� �����Ӹ��� Ŭ����
		return;
	}

	//������Ʈ�� �浹ó��
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

//���� �浹ó��
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

				//ó�� �浹��Ͽ��� ������ �浹������ ���ٸ� ó���浹.
				if (!(*iterSrc)->CheckCollisionList(*iterDest))
				{
					//���� ���� �浹������� �߰�
					(*iterSrc)->AddCollider(*iterDest);
					(*iterDest)->AddCollider(*iterSrc);

					(*iterSrc)->CallFunction(CS_ENTER,*iterDest,fDeltaTime);
					(*iterDest)->CallFunction(CS_ENTER ,*iterSrc, fDeltaTime);
				}
				else //���� �浹�������ִٸ� ��� �浹����.
				{
					(*iterSrc)->CallFunction(CS_STAY, *iterDest, fDeltaTime);
					(*iterDest)->CallFunction(CS_STAY, *iterSrc, fDeltaTime);
				}
			}
			//���� �浹�� �ȵ� ���¿��� ������ �浹�� �ǰ��־��ٸ�
			//���� �� �浹 ���¿��� �������ٴ� �ǹ�.
			else if((*iterSrc)->CheckCollisionList(*iterDest))
			{
				//���� �浹�� �ȵǹǷ� �浹��Ͽ��� ������.
				(*iterSrc)->EraseCollisionList(*iterDest);
				(*iterDest)->EraseCollisionList(*iterSrc);

				(*iterSrc)->CallFunction(CS_LEAVE, *iterDest, fDeltaTime);
				(*iterDest)->CallFunction(CS_LEAVE, *iterSrc, fDeltaTime);
			}
		}
	}
	return bCollision;
}
