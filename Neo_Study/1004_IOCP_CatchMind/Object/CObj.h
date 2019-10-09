#pragma once
#include "..\\value.h"

class CObj
{
protected:
	CObj();
	virtual ~CObj();
protected:
	int			m_iRef; //레퍼런스 카운트용

public:
	void AddRef() //레퍼런스 증가
	{
		++m_iRef;
	}
	int Release() // 레퍼런스 감소 및 삭제
	{
		--m_iRef;
		if (m_iRef == 0)
		{
			delete this;
			return 0;
		}

		return m_iRef;
	}

protected:
	string		m_strTag;
	POSITION	m_tPos;  //위치
	_SIZE		m_tSize; //크기

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

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
};

