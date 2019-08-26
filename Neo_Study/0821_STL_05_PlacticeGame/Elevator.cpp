#include "Elevator.h"

Elevator::Elevator(int max = 5, int floor = 1) //정원 수정해야함. 무게 받도록(하중)
{
	doorState = CLOSED;
	elevatorState = STOP;
	itsDirection = 1;
	itsFloor = floor;
	itsTimer = 0;
	maxPerson = max;
	weightLimit = 600;
	itsFlag = 1;
}

Elevator::~Elevator()
{
}

void Elevator::Operater()
{
	if (elevatorState == MOVING_UP)
	{
		// 초단위 시간을 얻기 위해 클록 함수에 의해 반환된 값을 CLOCKS_PER_SEC로 나눈 값.
		if ((clock() - itsTimer) >= 0.5f * CLOCKS_PER_SEC) //기본 1초당 1칸 올라/내려 가도록
		{
			elevatorState = STOP;
			itsFloor++;
			vElevator();
		}
	}

	if (elevatorState == MOVING_DOWN)
	{
		if ((clock() - itsTimer) >= 0.5f * CLOCKS_PER_SEC)
		{
			elevatorState = STOP;
			itsFloor--;
			vElevator();
		}
	}

	if (doorState == CLOSING)
	{
		if ((clock() - itsTimer) >= 1 * CLOCKS_PER_SEC)
		{
			doorState = CLOSED;
			vDoor();
		}

	}

	if (doorState == OPENING)
	{
		if ((clock() - itsTimer) >= 1 * CLOCKS_PER_SEC)
		{
			doorState = OPENED;
			vDoor();
		}
	}
}

void Elevator::MoveUp()
{
	itsTimer = clock();
	itsDirection = 1;
	elevatorState = MOVING_UP;
	vElevator();
}

void Elevator::MoveDown()
{
	itsTimer = clock();
	itsDirection = -1;
	elevatorState = MOVING_DOWN;
	vElevator();
}

void Elevator::Open()
{
	itsTimer = clock();
	doorState = OPENING;
	vDoor();
}

void Elevator::Close()
{
	itsTimer = clock();
	doorState = CLOSING;
	vDoor();
}

elvOver Elevator::IsitFull()
{
	elvOver returnValue = NO;

	if (Person.GetNumber() == maxPerson) // 하중 옵션 추가
		returnValue = FULL;
	if (Person.GetNumber() > maxPerson)
		returnValue = OVER;

	return returnValue;
}

elvDoor Elevator::GetDoorState()
{
	return doorState;
}

elvElevator Elevator::GetElevatorState()
{
	return elevatorState;
}

int Elevator::GetFlag()
{
	return itsFlag;
}

void Elevator::SetFlag(int newFlag)
{
	itsFlag = newFlag;
}

int Elevator::GetNumber()
{
	return Person.GetNumber();
}

int Elevator::GetDirection()
{
	return itsDirection;
}

int Elevator::GetFloor()
{
	return itsFloor;
}

void Elevator::GetIn(Floor& rFloor)
{
	if (IsitFull() == NO)
	{
		int temp;

		while (rFloor.GetPersonNumber(itsFloor, itsDirection) != 0)
		{
			temp = rFloor.PopPerson(itsFloor, itsDirection);
			Person.Push(temp);
		}
	}

	vInterface();
}

void Elevator::GetOut(Floor& rFloor)
{
	int i, temp;
	int number = Person.GetNumber();

	for (i = 0; i < number; i++)
	{
		temp = Person.Pop();
		if (temp != itsFloor)
			Person.Push(temp);
	}

	if (IsitFull() == OVER)
	{
		for (i = 0; i < maxPerson; i++)
		{
			temp = Person.Pop();
			Person.Push(temp);
		}

		number = Person.GetNumber();
		for (i = maxPerson; i < number; i++)
		{
			temp = Person.Pop();
			rFloor.PushPerson(itsFloor, temp);
		}
	}

	vInterface();
}

int Elevator::GetButton(int floor)
{
	int i, temp=0;
	int returnValue = 0;
	int number = Person.GetNumber();

	for (i = 0; i < number; i++)
	{
		temp = Person.Pop();
		if (temp == floor)
			returnValue = 1;
		Person.Push(temp);
	}

	return returnValue;
}

void Elevator::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}