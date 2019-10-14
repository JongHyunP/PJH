#pragma once
#include "../value.h"

typedef struct _tagKeyInfo
{
	string			strName;
	vector<DWORD>	vecKey;
	bool			bDown;
	bool			bPress;
	bool			bUp;

	_tagKeyInfo() :
		bDown(false),
		bPress(false),
		bUp(false)
	{
	}
}KEYINFO,*PKEYINFO;

class CInputManager
{
	DECLARE_SINGLE(CInputManager)
private:
	HWND							m_hWnd;
	unordered_map<string, PKEYINFO> m_mapKey;
	PKEYINFO						m_pCreateKey;

	POINT							m_tMousePos;
	POINT							m_tMouseMove;
	class CMouse*					m_pMouse;
public:
	class CMouse* GetMouse() const
	{
		return m_pMouse;
	}
public:
	bool Init(HWND hWnd);
	void Update(float fDeltaTime);
	bool KeyDown(const string& strKey) const;
	bool KeyPress(const string& strKey) const;
	bool KeyUp(const string& strKey) const;


public:
	template <typename T>
	bool AddKey(const T& data)
	{
		const char* pType = typeid(T).name(); // Ÿ���� ���ڿ���

		if (strcmp(pType, "char") == 0 || strcmp(pType, "int") == 0)
		{
			m_pCreateKey->vecKey.push_back((DWORD)data);
		}
		else
		{
			m_pCreateKey->strName = data;
			m_mapKey.insert(make_pair(m_pCreateKey->strName, m_pCreateKey));
		}

		return true;
	}
	template <typename T, typename ... Types>
	bool AddKey(const T& data, const Types& ... arg)
	{
		if (!m_pCreateKey)
		{
			m_pCreateKey = new KEYINFO;
		}

		const char* pType = typeid(T).name(); // Ÿ���� ���ڿ���

		if (strcmp(pType, "char") == 0 || strcmp(pType, "int") == 0)
		{
			m_pCreateKey->vecKey.push_back((DWORD)data);
		}
		else
		{
			m_pCreateKey->strName = data;
			m_mapKey.insert(make_pair(m_pCreateKey->strName, m_pCreateKey));
		}

		//���, �ϳ��� ��������  AddKey(const T& data)�� ȣ��
		AddKey(arg...);

		if (m_pCreateKey)
		{
			m_pCreateKey = NULL; //��������� ������ ���� �ʱ�ȭ
		}

		return true;
	}

private:
	PKEYINFO FindKey(const string& strKey) const;
};

