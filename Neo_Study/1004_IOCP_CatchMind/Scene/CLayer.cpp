#include "CLayer.h"
#include "..\\Object\CObj.h"

CLayer::CLayer() : 
	m_iZOrder(0),
	m_strTag(""),
	m_pScene(NULL), 
	m_bLayerEnable(true),
	m_bLayerLife(true)
{

}

CLayer::~CLayer()
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		CObj::EraseObj(*iter);
		SAFE_RELEASE((*iter));
	}
	
	m_ObjList.clear();
}

void CLayer::AddObject(CObj * pObj)
{
	pObj->SetScene(m_pScene);
	pObj->SetLayer(this);
	pObj->AddRef();

	m_ObjList.push_back(pObj);
}

void CLayer::Input(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //���̾ ��Ȱ��ȭ�̸�
		{
			++iter; //�ش� ���̾�� ����
			continue;
		}
		//Ȱ��ȭ�� �״�� ���
		(*iter)->Input(fDeltaTime);

		//������
		if (!(*iter)->GetLife())
		{
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}

int CLayer::Update(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //���̾ ��Ȱ��ȭ�̸�
		{
			++iter; //�ش� ���̾�� ����
			continue;
		}
		//Ȱ��ȭ�� �״�� ���
		(*iter)->Update(fDeltaTime);

		//������
		if (!(*iter)->GetLife())
		{
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}

	return 0;
}

int CLayer::LateUpdate(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //���̾ ��Ȱ��ȭ�̸�
		{
			++iter; //�ش� ���̾�� ����
			continue;
		}
		//Ȱ��ȭ�� �״�� ���
		(*iter)->LateUpdate(fDeltaTime);

		//������
		if (!(*iter)->GetLife())
		{
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
	return 0;
}

void CLayer::Collision(float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //���̾ ��Ȱ��ȭ�̸�
		{
			++iter; //�ش� ���̾�� ����
			continue;
		}
		//Ȱ��ȭ�� �״�� ���
		(*iter)->Collision(fDeltaTime);

		//������
		if (!(*iter)->GetLife())
		{
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}

void CLayer::Render(HDC hdc, float fDeltaTime)
{
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetEnable()) //���̾ ��Ȱ��ȭ�̸�
		{
			++iter; //�ش� ���̾�� ����
			continue;
		}
		//Ȱ��ȭ�� �״�� ���
		(*iter)->Render(hdc,fDeltaTime);

		//������
		if (!(*iter)->GetLife())
		{
			CObj::EraseObj(*iter);
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
		}
		else
		{
			++iter;
		}
	}
}
