#include "CResourceManager.h"
#include "CTexture.h"

DEFINITION_SINGLE(CResourceManager)

CResourceManager::CResourceManager()
{

}

CResourceManager::~CResourceManager()
{
	SAFE_RELEASE(m_pBackBuffer); // 증가되있는 상태니 한번지워줌.
	Safe_Release_Map(m_mapTexture);
}

CTexture* CResourceManager::GetBackBuffer() const
{
	m_pBackBuffer->AddRef();
	return m_pBackBuffer;
}

bool CResourceManager::Init(HINSTANCE hInst, HDC hdc)
{
	m_hInst = hInst;
	m_hDC = hdc;

	//백버퍼 불러오기
	m_pBackBuffer = LoadTexture("BackBuffer", L"BackBuffer.bmp");

	return true;
}

CTexture* CResourceManager::LoadTexture(const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	CTexture* pTexture = FindTexture(strKey);

	if (pTexture) //이미 존재하면 리턴
	{
		return pTexture;
	}

	//없으면 만들어주자
	pTexture = new CTexture;
	if (!pTexture->LoadTexture(m_hInst, m_hDC,strKey, pFileName, strPathKey))
	{
		//실패하면 없애고
		SAFE_RELEASE(pTexture);
		return NULL;
	}

	// 로드 성공하면 맵에 넣어주자
	pTexture->AddRef(); //참조+1
	m_mapTexture.insert(make_pair(strKey, pTexture));

	return pTexture;
}

CTexture* CResourceManager::FindTexture(const string& strKey)
{
	unordered_map<string, class CTexture*>::iterator iter = m_mapTexture.find(strKey);

	if (iter == m_mapTexture.end())
	{
		return NULL;
	}

	// 하나만 불러서 공유하기 위해 (메모리 절약)
	iter->second->AddRef();

	return iter->second;
}
