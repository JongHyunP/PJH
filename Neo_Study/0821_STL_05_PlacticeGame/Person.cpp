#include "Person.h"
#include "PublicIncludeHeader.h"


Person::Person()
{
}


Person::~Person()
{
}

int Person::GetNowFloor()
{
	return nowFloor;
}

void Person::SetNowFloor(int pNowFloor)
{
	nowFloor = pNowFloor;
}

int Person::GetTarget()
{
	return targetFloor;
}

void Person::SetTarget(int pTarget)
{
	targetFloor = pTarget;
}

int Person::GetKg()
{
	return kg;
}

void Person::SetKg(int pKg)
{
	kg = pKg;
}