#include "TestManager.h"

int main()
{
	srand((unsigned int)time(NULL));
	TestManager TM;

	TM.TestManagerInitialize();
	TM.CreateRamdomPerson();
	TM.ShowFloor();


	return 0;
}