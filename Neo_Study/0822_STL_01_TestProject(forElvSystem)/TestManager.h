#pragma once
#include "Person.h"

#define MAX_FLOOR 20
#define MIN_KG 40
#define MAX_KG 80

class TestManager : protected Person
{
	map<int,int, greater<int>> floor;
public:
	TestManager();
	virtual ~TestManager();
	void TestManagerInitialize();
	void CreateRamdomPerson();
	void ShowFloor();
	void UpdateNewPerson(int targetFloor);
	void CallElv();
	void DrowB();
};

