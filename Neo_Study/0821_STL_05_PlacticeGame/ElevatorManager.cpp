#include "ElevatorManager.h"
#include "PublicIncludeHeader.h"

//체크 사람 추가 (사람클래스에서 알아서 리스트 구조로 생성)

//엘레베이터 콜

ElevatorManager::ElevatorManager(Floor& rFloor, int max)
{
	pFloor = &rFloor;
	maxFloor = max;
	pElevator = 0;
}

ElevatorManager::~ElevatorManager()
{
}

int ElevatorManager::DecideOpen()
{
	int returnValue = 0;
	int floor = pElevator->GetFloor();
	int direction = pElevator->GetDirection();

	if (pElevator->GetButton(floor) == 1)
		returnValue = 1;

	if (pElevator->IsitFull() == NO)
		if (pFloor->GetPersonNumber(floor, direction) != 0)
			returnValue = 1;

	return returnValue;
}

int ElevatorManager::DecideDirection()
{
	int returnValue;
	int floor = pElevator->GetFloor();
	int direction = pElevator->GetDirection();
	int i;

	returnValue = direction;

	if (direction == 1)
	{
		if (pFloor->GetPersonNumber(floor, -1) != 0)
			returnValue = -1;

		for (i = floor - 1; i >= 1; i--)
		{
			if (pElevator->GetButton(i) == 1)
				returnValue = -1;
			if (pFloor->GetButton(i) == 1)
				returnValue = -1;
		}

		for (i = floor + 1; i <= maxFloor; i++)
		{
			if (pElevator->GetButton(i) == 1)
				returnValue = 1;

			if (pFloor->GetButton(i) == 1)
				returnValue = 1;
		}
	}
	else
	{
		if (pFloor->GetPersonNumber(floor, 1) != 0)
			returnValue = 1;
		for (i = floor + 1; i <= maxFloor; i++)
		{
			if (pElevator->GetButton(i) == 1)
				returnValue = 1;

			if (pFloor->GetButton(i) == 1)
				returnValue = 1;
		}

		for (i = floor - 1; i >= 1; i--)
		{
			if (pElevator->GetButton(i) == 1)
				returnValue = -1;
			if (pFloor->GetButton(i) == 1)
				returnValue = -1;
		}
	}

	return returnValue;
}

int ElevatorManager::DecideMoving()
{
	int returnValue = 0;
	int i;

	for (i = 1; i <= maxFloor; i++)
	{
		if (pElevator->GetButton(i) != 0)
			returnValue = 1;

		if (pFloor->GetPersonNumber(i, 1) != 0)
			returnValue = 1;

		if (pFloor->GetPersonNumber(i, -1) != 0)
			returnValue = 1;
	}

	return returnValue;
}


int ElevatorManager::DecideOperate()
{
	elvElevator elevator = pElevator->GetElevatorState();
	elvDoor door = pElevator->GetDoorState();

	int returnValue = 1;

	if (elevator == MOVING_UP || elevator == MOVING_DOWN)
		returnValue = 0;
	if (door == CLOSING || door == OPENING)
		returnValue = 0;

	return returnValue;
}

void ElevatorManager::Operator(Elevator& rElevator)
{
	pElevator = &rElevator;
	int flag = pElevator->GetFlag();

	if (DecideOperate() == 1)
	{
		switch (flag)
		{
		case 1:
			if (DecideMoving() == 1)
			{
				pElevator->SetDirection(DecideDirection());

				if (DecideOpen())
				{
					pElevator->SetFlag(3);
				}
				else
				{
					if (pElevator->GetDirection() == 1)
						pElevator->MoveUp();
					else
						pElevator->MoveDown();
				}
			}
			break;
		case 3:
			pElevator->Open();
			pElevator->SetFlag(4);
			break;
		case 4:
			pElevator->GetOut(*pFloor);
			pElevator->GetIn(*pFloor);
			pElevator->SetFlag(5);
			break;
		case 5:
			pElevator->Close();
			pElevator->SetFlag(6);
			break;
		case 6:
			if (pElevator->IsitFull() == OVER)
				pElevator->SetFlag(3);
			else
				pElevator->SetFlag(1);
			break;
		}
	}
}