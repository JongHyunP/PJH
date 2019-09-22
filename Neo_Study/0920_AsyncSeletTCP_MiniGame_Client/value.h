#pragma once
#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>

using namespace std;

//����� ���� ���
#include "defines.h"

//Ÿ�Ժ� �Է¿�
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