#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map> //해쉬 기반 탐색이라 일반 맵보다 빠름
#include <string>
#include <sstream>
#include <memory>

using namespace std;

//사용자 정의 헤더
#include "defines.h"
#include "resource.h"
#include "Types.h"
#include "flag.h"

//벡터나 리스트를 안전하게 소멸하는 용
template <typename T>
void Safe_Delete_VecList(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}

	p.clear();
}

template <typename T>
void Safe_Release_VecList(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(*iter);
	}

	p.clear();
}