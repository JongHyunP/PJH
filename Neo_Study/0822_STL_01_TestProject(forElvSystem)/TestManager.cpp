#include "TestManager.h"



TestManager::TestManager()
{
	
}


TestManager::~TestManager()
{
}

void TestManager::TestManagerInitialize()
{
	for (int i = 1; i < MAX_FLOOR + 1 ; i++)
	{
		floor.insert(pair<int, int>(i, 0));
	}
}

//체크 사람 추가 (사람클래스에서 알아서 리스트 구조로 생성)

//엘레베이터 콜

//
void TestManager::UpdateNewPerson(int targetFloor)
{
	floor[targetFloor] ++;
}

void TestManager::CreateRamdomPerson()
{
	//rand() % 100 + 1  은 1부터 100까지
	Person* p1 = new Person();
	p1->SetKg(rand() % (MAX_KG - MIN_KG) + MIN_KG);
	p1->SetTarget(rand() % MAX_FLOOR + 1);

	
	cout << p1->GetTarget() << endl;
	cout << p1->GetKg() << endl;

	UpdateNewPerson(p1->GetTarget());

	delete p1;
}

void TestManager::CallElv()
{
	//엘베 객체들 다 받고
}

void TestManager::ShowFloor()
{
	map<int, int,greater<int>>::iterator iter;
	for (iter = floor.begin(); iter != floor.end(); ++iter)
	{
		cout << iter->first << "F -> 손님 :" << iter->second << endl;
	}
}

void TestManager::DrowB()
{

}