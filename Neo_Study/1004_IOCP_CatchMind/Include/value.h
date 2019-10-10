#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map> //�ؽ� ��� Ž���̶� �Ϲ� �ʺ��� ����
#include <string>
#include <sstream>
#include <memory>

#include <crtdbg.h> // �޸𸮸� �˻��

using namespace std;

//����� ���� ���
#include "defines.h"
#include "resource.h"
#include "Types.h"
#include "flag.h"

//��Ŷ��� ��ũ
//#include "..\..\..\\Study_Server-NEO-\1007_CatchMind_Server\Common\PACKET_HEADER_CATCH_MIND.h" //��
//#include "..\..\..\..\..\source\repos\Study_Server-NEO-\1007_CatchMind_Server\Common\PACKET_HEADER_CATCH_MIND.h" //�׿���

//Path Key
#define ROOT_PATH		"RootPath"
#define	TEXTURE_PATH	"TexturePath"

//���ͳ� ����Ʈ�� �����ϰ� �Ҹ��ϴ� ��
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

template <typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}

	p.clear();
}

template <typename T>
void Safe_Release_Map(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);
	}

	p.clear();
}