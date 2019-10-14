#pragma once
#include "../value.h"

class CRef
{
protected:
	CRef();
	virtual ~CRef();
protected:
	int				m_iRef;
	bool			m_bEnable; //객체 활성 비활성
	bool			m_bLife;
	string			m_strTag;
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
	void SetTag(const string& strTag)
	{
		m_strTag = strTag;
	}
	void SetEnable(bool bEnable)
	{
		m_bEnable = bEnable;
	}
	void Die()
	{
		m_bLife = false;
	}
	string GetTag() const
	{
		return m_strTag;
	}
	bool GetEnable() const
	{
		return m_bEnable;
	}
	bool GetLife() const
	{
		return m_bLife;
	}
};

