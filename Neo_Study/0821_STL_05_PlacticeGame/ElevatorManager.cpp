#include "ElevatorManager.h"
#include "PublicIncludeHeader.h"

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

	if (direction == Decide_Direction::DECIDE_UP)
	{
		if (pFloor->GetPersonNumber(floor, FloorDirection::DOWN) != 0)
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
	else if(direction == Decide_Direction::DECIDE_DOWN)
	{
		if (pFloor->GetPersonNumber(floor, FloorDirection::UP) != 0)
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

int ElevatorManager::DecideMoving() // 사람이 있는층에 리턴값 1 
{
	int returnValue = 0;

	for (int i = 1; i <= maxFloor; i++)
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


int ElevatorManager::DecideOperate() //엘레베이터/문 이(가) ~하는 상태면 이라면 멈추게함
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

void ElevatorManager::Operator(Elevator& rElevator) //직접적인 행동에대한 판단
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

				if (DecideOpen()) //열어줘야하는지
				{
					pElevator->SetFlag(3);
				}
				else //아니니까 올라가자/내려가자 판단
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