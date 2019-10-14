#pragma once
#include "../Core/CRef.h"
#include "../Collider/CCollider.h"

class CObj : 
	public CRef
{
protected:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();

private:
	static list<CObj*> m_ObjectList;
	static unordered_map<string, CObj*> m_mapPrototype;

public:
	static void AddObj(CObj* pObj);
	static CObj* FindObject(const string& strTag);
	static void EraseObj(CObj* pObj);
	static void EraseObj(const string& strTag);
	static void EraseObj();
	static void ErasePrototype(const string& strTag);
	static void ErasePrototype();

protected:
	class CScene* m_pScene;
	class CLayer* m_pLayer;

public:
	void SetScene(class CScene* pScene)
	{
		m_pScene = pScene;
	}
	void SetLayer(class CLayer* pLayer)
	{
		m_pLayer = pLayer;
	}
	class CScene* GetScene() const
	{
		return m_pScene;
	}
	class CLayer* GetLayer() const
	{
		return m_pLayer;
	}

protected:
	string			m_strTag;
	POSITION		m_tPos;  //위치
	_SIZE			m_tSize; //크기
	POSITION		m_tPivot; //피봇
	class CTexture* m_pTexture;
	list<CCollider*>  m_ColliderList;

public:
	const list<CCollider*>* GetColliderList() const
	{
		return &m_ColliderList;
	}
	CCollider* GetCollider(const string& strTag);

public:
	template <typename T>
	void AddCollisionFunction(const string& strTag,COLLISION_STATE eState, T* pObj, void(T::* pFunc)(CCollider*, CCollider*, float))
	{
		list<CCollider*>::iterator iter;
		list<CCollider*>::iterator iterEnd = m_ColliderList.end();

		for (iter = m_ColliderList.begin(); iter != iterEnd; ++iter)
		{
			if ((*iter)->GetTag() == strTag)
			{
				(*iter)->AddCollisionFunction(eState, pObj, pFunc);
				break;
			}
		}

	}

	template <typename T>
	T* AddCollider(const string& strTag)
	{
		T* pCollider = new T;
		pCollider->SetObj(this);
		pCollider->SetTag(strTag);

		if (!pCollider->Init())
		{
			SAFE_RELEASE(pCollider);
			return NULL;
		}

		pCollider->AddRef();
		m_ColliderList.push_back(pCollider);

		return pCollider;
	}
	bool CheckCollider()
	{
		return !m_ColliderList.empty(); //비어있으면 false 충돌체있으면 true
	}
public:
	string GetTag() const
	{
		return m_strTag;
	}
	POSITION GetPosition() const
	{
		return m_tPos;
	}
	_SIZE GetSize() const
	{
		return m_tSize;
	}
	POSITION GetPivot() const
	{
		return m_tPivot;
	}
public:
	void SetTag(const string& strTag)
	{
		m_strTag = strTag;
	}
	void SetPos(const POSITION& tPos)
	{
		m_tPos = tPos;
	}
	void SetPos(const POINT& tPos)
	{
		m_tPos = tPos;
	}
	void SetPos(float x, float y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}
	void SetSize(const _SIZE& tSize)
	{
		m_tSize = tSize;
	}
	void SetSize(float x, float y)
	{
		m_tSize.x = x;
		m_tSize.y = y;
	}
	void SetPivot(const _SIZE& tPivot)
	{
		m_tPivot = tPivot;
	}
	void SetPivot(float x, float y)
	{
		m_tPivot.x = x;
		m_tPivot.y = y;
	}
public:
	void SetTexture(class CTexture* pTexture);
	void SetTexture(const string& strKey, const wchar_t* pFileName = NULL,
					const string& strPathKey = TEXTURE_PATH);
public:
	virtual bool Init() = 0 ;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CObj* Clone() = 0;

public:
	template <typename T>
	static T * CreateObj(const string& strTag, class CLayer* pLayer = NULL)
	{
		T* pObj = new T;

		pObj->SetTag(strTag);

		if (!pObj->Init())
		{
			SAFE_DELETE(pObj);
			return NULL;
		}

		if (pLayer)
		{
			pLayer->AddObject(pObj);
		}

		//스태틱 함수 호출
		AddObj(pObj);

		return pObj;
	}

	//프로토타입을 복사해서 생성하는 용도
	static CObj* CreateCloneObj(const string& strPrototypeKey, const string& strTag,
		class CLayer* pLayer = NULL);

	//프로토타입 생성용
	template <typename T>
	static T * CreatePrototype(const string& strTag)
	{
		T* pObj = new T;

		pObj->SetTag(strTag);

		if (!pObj->Init())
		{
			SAFE_DELETE(pObj);
			return NULL;
		}

		pObj->AddRef();
		m_mapPrototype.insert(make_pair(strTag, pObj));

		return pObj;
	}


private:
	static CObj* FindPrototype(const string& strKey);
};

