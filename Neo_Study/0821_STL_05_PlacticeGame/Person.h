#pragma once
class Person
{
protected:
	int targetFloor;
	int kg;
	int nowFloor;
	list<Person> *person;
public:
	Person();
	~Person();
	int GetNowFloor();
	void SetNowFloor(int pNowFloor);
	int GetTarget();
	void SetTarget(int pTarget);
	int GetKg();
	void SetKg(int pKg);
};

