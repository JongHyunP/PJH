#include "Person.h"

Person::~Person()
{
}

void Person::CreateRamdomPerson()
{
	
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