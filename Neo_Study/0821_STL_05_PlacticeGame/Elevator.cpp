#include "Elevator.h"

Elevator::Elevator(int max = 5, int floor = 1) //정원 수정해야함. 무게 받도록(하중)
{
	doorState = CLOSED;
	elevatorState = STOP;
	itsDirection = 1;
	itsFloor = floor;
	itsTimer = 0;
	maxPerson = max;
	itsFlag = 1;
}

Elevator::~Elevator()
{
}

void Elevator::Operater()
{
	if (elevatorState == MOVING_UP)
	{
		if ((clock() - itsTimer) >= 1 * CLK_TCK) //기본 1초당 1칸 올라/내려 가도록
		{
			elevatorState = STOP;
			itsFloor++;
			dContainer();
		}
	}

	if (elevatorState == MOVING_DOWN)
	{
		if ((clock() - itsTimer) >= 1 * CLK_TCK)
		{
			elevatorState = STOP;
			itsFloor--;
			dContainer();
		}
	}

	if (doorState == CLOSING)
	{
		if ((clock() - itsTimer) >= 2 * CLK_TCK)
		{
			doorState = CLOSED;
			dDoor();
		}

	}

	if (doorState == OPENING)
	{
		if ((clock() - itsTimer) >= 2 * CLK_TCK)
		{
			doorState = OPENED;
			dDoor();
		}
	}
}

void Elevator::MoveUp()
{
	itsTimer = clock();
	itsDirection = 1;
	elevatorState = MOVING_UP;
	dContainer();
}

void Elevator::MoveDown()
{
	itsTimer = clock();
	itsDirection = -1;
	elevatorState = MOVING_DOWN;
	dContainer();
}

void Elevator::Open()
{
	itsTimer = clock();
	doorState = OPENING;
	dDoor();
}

void Elevator::Close()
{
	itsTimer = clock();
	doorState = CLOSING;
	dDoor();
}

elvOver Elevator::IsitFull()
{
	elvOver returnValue = NO;

	if (Person.GetNumber() == maxPerson)
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

	dButton();
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

	dButton();
}

int Elevator::GetButton(int floor)
{
	int i, temp;
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