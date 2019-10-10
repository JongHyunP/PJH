#pragma once
#include "../value.h"

class PathManager
{
	DECLARE_SINGLE(PathManager)
private:
	unordered_map<string, wstring> m_mapPath;

public:
	bool Init();
	bool CreatePath(const string& strKey, const wchar_t* pPath, 
		const string& strBaseKey = ROOT_PATH);
	const wchar_t* FindPath(const string& strKey);
};

