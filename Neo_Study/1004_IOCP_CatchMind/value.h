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

using namespace std;

//����� ���� ���
#include "defines.h"


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