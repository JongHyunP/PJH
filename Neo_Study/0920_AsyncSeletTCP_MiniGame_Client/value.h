#pragma once
#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>

using namespace std;

//사용자 정의 헤더
#include "defines.h"

//타입별 입력용
template <typename T>
T Input()
{
	T data;
	cin >> data;
	if (cin.fail)
	{
		cin.clear();
		cin.ignore(1024,"\n");
		return 0;
	}

	return data;
}

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