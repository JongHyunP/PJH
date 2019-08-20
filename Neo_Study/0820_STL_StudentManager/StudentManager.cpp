#include "StudentManager.h"
#include <iostream>
#include "ScienceStudent.h"
#include "NAStudent.h"
#include <algorithm>

using namespace std;

StudentManager::StudentManager()
{
	st.reserve(20);
}


StudentManager::~StudentManager()
{
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		delete *iter;
	}

	st.clear();
}

void StudentManager::LoadFile()
{
	FILE* pFile = fopen("save.txt", "r");
	if (pFile != nullptr)
	{
		int iCount = 0;
		fscanf(pFile, "%d\n", &iCount);
		for (int i = 0; i < iCount; i++)
		{
			//Student* pNew = new Student();
			//pNew->LoadStudent(pFile);
			//st.push_back(pNew);
		}
		fclose(pFile);
	}
}

void StudentManager::PrintMenu()
{
	cout << "1.�Է�" << endl;
	cout << "2.���" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
}


void StudentManager::InputStudent()
{
	int input = 0;
	cout << "����1 �̰�2" << endl;
	cin >> input;

	Student* pNew = nullptr;
	if (input == 1)
	{
		pNew = new NAStudent();
	}
	else if (input == 2)
	{
		pNew = new ScienceStudent();
	}
	pNew->InputLine(st.size());
	st.push_back(pNew);
}

void StudentManager::OutputStudent()
{
	cout << "��ȣ\t�̸�\t����\t����\t����\t����\t��2\t����\t���" << endl;
	//vector<Student*>::iterator
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		(*iter)->PrintLine();
	}
}

void StudentManager::SaveFile()
{
	FILE* pFile = fopen("save.txt", "w");
	fprintf(pFile, "%d\n", st.size());
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		(*iter)->SaveStudent(pFile);
	}
	fclose(pFile);
}

void StudentManager::Sort()
{
	int input = 0;
	cout << "1.������� ���� 2.��ձ��� ����" << endl;
	cin >> input;
	StudentManager* pStu = sptr.get();

	if (input == 1)
	{
		cout << "1.�������� ���� 2.�ø����� ����" << endl;
		cin >> input;
		if (input == 1)
		{
			Less();
		}
		else if(input==2)
		{
			Greater();
		}
	}
	else if (input == 2)
	{
		cout << "1.�������� ���� 2.�ø����� ����" << endl;
		cin >> input;
		if (input == 1)
		{
			Less(); 
		}
		else if (input == 2)
		{
			Greater();
		}
	}
	else
	{
		Sort();
	}
}

void StudentManager::Less()
{

	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l < r; }); // ���ٽ�, �Լ���ü�� �ٷ� �����ϴ°�.// [] ĸ�Ĵ� �ʿ��Ѱ��� ������ ���°Ŷ������ϸ��. 
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
}

void StudentManager::Greater()
{
	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l > r; }); // ���ٽ�, �Լ���ü�� �ٷ� �����ϴ°�.// [] ĸ�Ĵ� �ʿ��Ѱ��� ������ ���°Ŷ������ϸ��. 
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
}

