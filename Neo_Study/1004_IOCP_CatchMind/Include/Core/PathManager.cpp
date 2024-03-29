#include "PathManager.h"

DEFINITION_SINGLE(PathManager)

PathManager::PathManager()
{

}
PathManager::~PathManager()
{

}

bool PathManager::Init()
{
	wchar_t strPath[MAX_PATH] = {}; //260개짜리 배열

	GetModuleFileName(NULL, strPath, MAX_PATH);

	for (int i = lstrlen(strPath) - 1; i >= 0; --i)
	{
		if (strPath[i] == '/' || strPath[i] == '\\')
		{
			memset(strPath + (i + 1), 0, sizeof(wchar_t) * (MAX_PATH - (i + 1)));
			break;
		}
	}

	m_mapPath.insert(make_pair(ROOT_PATH, strPath));

	//Texture 경로 설정
	if (!CreatePath(TEXTURE_PATH, L"Texture\\"))
	{
		return false;
	}

	return true;
}

bool PathManager::CreatePath(const string& strKey, const wchar_t* pPath, const string& strBaseKey)
{
	const wchar_t* pBasePath = FindPath(strBaseKey);

	wstring strPath;

	if (pBasePath)
	{
		strPath = pBasePath;
	}

	strPath += pPath;

	m_mapPath.insert(make_pair(strKey, strPath));

	return true;
}

const wchar_t* PathManager::FindPath(const string& strKey)
{
	unordered_map<string, wstring>::iterator  iter = m_mapPath.find(strKey);

	if (iter == m_mapPath.end())
	{
		return NULL;
	}

	return iter->second.c_str();
}
