#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <deque>
#include <map>
#include <cstdlib>
#include <time.h>

using namespace std;

class Person
{
	
	int targetFloor;
	int kg;
public:
	Person() :targetFloor(0), kg(0) {};
	virtual ~Person();
	virtual void CreateRamdomPerson();
	virtual int GetTarget();
	virtual void SetTarget(int pTarget);
	virtual int GetKg();
	virtual void SetKg(int pKg);
};

