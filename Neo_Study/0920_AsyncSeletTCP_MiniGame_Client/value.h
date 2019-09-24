#pragma once
#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <unordered_map> //해쉬 기반 탐색이라 일반 맵보다 빠름
#include <string>

using namespace std;

//사용자 정의 헤더
#include "defines.h"
#include "Flags.h"

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

template <typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		//세컨드가 value
		SAFE_DELETE(iter->second);
	}

	p.clear();
}

