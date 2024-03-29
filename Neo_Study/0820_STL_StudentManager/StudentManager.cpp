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
	cout << "1.입력" << endl;
	cout << "2.출력" << endl;
	cout << "3.저장" << endl;
	cout << "4.종료" << endl;
	cout << "5.정렬" << endl;
}


void StudentManager::InputStudent()
{
	int input = 0;
	cout << "문과1 이과2" << endl;
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
	cout << "번호\t이름\t국어\t영어\t수학\t역사\t수2\t총점\t평균" << endl;
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
	cout << "1.국어기준 정렬 2.평균기준 정렬" << endl;
	cin >> input;
	StudentManager* pStu = sptr.get();

	if (input == 1)
	{
		cout << "1.내림차순 정렬 2.올림차순 정렬" << endl;
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
		cout << "1.내림차순 정렬 2.올림차순 정렬" << endl;
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

	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l < r; }); // 람다식, 함수객체를 바로 생성하는것.// [] 캡쳐는 필요한것을 가져다 쓰는거라고생각하면됨. 
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
}

void StudentManager::Greater()
{
	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l > r; }); // 람다식, 함수객체를 바로 생성하는것.// [] 캡쳐는 필요한것을 가져다 쓰는거라고생각하면됨. 
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
}

