#include "Elevator.h"

Elevator::Elevator(int max = 5, int floor = 1, int elvNum =1) //정원 수정해야함. 무게 받도록(하중)
{
	doorState = CLOSED;
	elevatorState = STOP;
	itsDirection = 1;
	itsFloor = floor;
	itsTimer = 0;
	maxPerson = max;
	weightLimit = 600;
	itsFlag = 1;
	elvNumber = elvNum;
}

Elevator::~Elevator()
{
}

void Elevator::Operater()
{
	if (elevatorState == MOVING_UP)
	{
		// 초단위 시간을 얻기 위해 클록 함수에 의해 반환된 값을 CLOCKS_PER_SEC로 나눈 값.
		if ((clock() - itsTimer) >= 1 * CLOCKS_PER_SEC) //기본 1초당 1칸 올라/내려 가도록
		{
			elevatorState = STOP;
			itsFloor++;
			DrowElevator();
		}
	}

	if (elevatorState == MOVING_DOWN)
	{
		if ((clock() - itsTimer) >= 1 * CLOCKS_PER_SEC)
		{
			elevatorState = STOP;
			itsFloor--;
			DrowElevator();
		}
	}

	if (doorState == CLOSING)
	{
		if ((clock() - itsTimer) >= 2 * CLOCKS_PER_SEC)
		{
			doorState = CLOSED;
			DrowElevator();
		}

	}

	if (doorState == OPENING)
	{
		if ((clock() - itsTimer) >= 2 * CLOCKS_PER_SEC)
		{
			doorState = OPENED;
			DrowElevator();
		}
	}
}

void Elevator::MoveUp()
{
	itsTimer = clock();
	itsDirection = 1;
	elevatorState = MOVING_UP;
	DrowElevator();
}

void Elevator::MoveDown()
{
	itsTimer = clock();
	itsDirection = -1;
	elevatorState = MOVING_DOWN;
	DrowElevator();
}

void Elevator::Open()
{
	itsTimer = clock();
	doorState = OPENING;
	DrowElevator();
}

void Elevator::Close()
{
	itsTimer = clock();
	doorState = CLOSING;
	DrowElevator();
}

ELEVATOR_FULL Elevator::IsitFull()
{
	ELEVATOR_FULL returnValue = NO;

	if (Person.GetNumber() == maxPerson) // 하중 옵션 추가
		returnValue = FULL;
	if (Person.GetNumber() > maxPerson)
		returnValue = OVER;

	return returnValue;
}

ELEVATOR_DOOR Elevator::GetDoorState()
{
	return doorState;
}

ELEVATOR_STATE Elevator::GetElevatorState()
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

	DrowElevatorInterface();
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

	DrowElevatorInterface();
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

void Elevator::DrowElevator()
{
	if (elvNumber == 1)
	{
		int x, y;

		x = 32;
		y = -2 * GetFloor() + 43;

		if (GetElevatorState() == MOVING_UP)
			y--;

		if (GetElevatorState() == MOVING_DOWN)
			y++;


		Gotoxy(x, y - 1);
		cout << "   ";
		Gotoxy(x, y + 3);
		cout << "   ";
		Gotoxy(x - 2, y - 1);
		cout << "   ";
		Gotoxy(x - 2, y + 3);
		cout << "   ";


		switch (GetDoorState())
		{
		case OPENED:
			Gotoxy(x - 3, y);
			cout << "①■■";
			Gotoxy(x - 3, y + 1);
			cout << "■□■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		case OPENING:
		case CLOSING:
			Gotoxy(x - 3, y);
			cout << "①■■";
			Gotoxy(x - 3, y + 1);
			cout << "■▥■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		case CLOSED:
			Gotoxy(x - 3, y);
			cout << "①■■";
			Gotoxy(x - 3, y + 1);
			cout << "■■■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		}
	}

	else if (elvNumber == 2)
	{
		int x, y;

		x = 49;
		y = -2 * GetFloor() + 43;

		if (GetElevatorState() == MOVING_UP)
			y--;

		if (GetElevatorState() == MOVING_DOWN)
			y++;

		Gotoxy(x + 2, y - 1);
		cout << "   ";
		Gotoxy(x + 2, y + 3);
		cout << "   ";
		Gotoxy(x + 2 + 2, y + 3);
		cout << "   ";
		Gotoxy(x + 2 + 2, y - 1);
		cout << "   ";


		switch (GetDoorState())
		{
		case OPENED:
			Gotoxy(x + 2, y);
			cout << "②■■";
			Gotoxy(x + 2, y + 1);
			cout << "■□■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		case OPENING:
		case CLOSING:
			Gotoxy(x + 2, y);
			cout << "②■■";
			Gotoxy(x + 2, y + 1);
			cout << "■▥■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		case CLOSED:
			Gotoxy(x + 2, y);
			cout << "②■■";
			Gotoxy(x + 2, y + 1);
			cout << "■■■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		}
	}

	else if (elvNumber == 3)
	{
		int x, y;

		x = 25;
		y = -2 * GetFloor() + 43;

		if (GetElevatorState() == MOVING_UP)
			y--;

		if (GetElevatorState() == MOVING_DOWN)
			y++;


		Gotoxy(x, y - 1);
		cout << "   ";
		Gotoxy(x, y + 3);
		cout << "   ";
		Gotoxy(x - 2, y - 1);
		cout << "   ";
		Gotoxy(x - 2, y + 3);
		cout << "   ";


		switch (GetDoorState())
		{
		case OPENED:
			Gotoxy(x - 3, y);
			cout << "③■■";
			Gotoxy(x - 3, y + 1);
			cout << "■□■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		case OPENING:
		case CLOSING:
			Gotoxy(x - 3, y);
			cout << "③■■";
			Gotoxy(x - 3, y + 1);
			cout << "■▥■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		case CLOSED:
			Gotoxy(x - 3, y);
			cout << "③■■";
			Gotoxy(x - 3, y + 1);
			cout << "■■■";
			Gotoxy(x - 3, y + 2);
			cout << "■■■";
			break;
		}
	}

	else if (elvNumber == 4)
	{
		int x, y;

		x = 56;
		y = -2 * GetFloor() + 43;

		if (GetElevatorState() == MOVING_UP)
			y--;

		if (GetElevatorState() == MOVING_DOWN)
			y++;

		Gotoxy(x + 2, y - 1);
		cout << "   ";
		Gotoxy(x + 2, y + 3);
		cout << "   ";
		Gotoxy(x + 2 + 2, y + 3);
		cout << "   ";
		Gotoxy(x + 2 + 2, y - 1);
		cout << "   ";


		switch (GetDoorState())
		{
		case OPENED:
			Gotoxy(x + 2, y);
			cout << "④■■";
			Gotoxy(x + 2, y + 1);
			cout << "■□■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		case OPENING:
		case CLOSING:
			Gotoxy(x + 2, y);
			cout << "④■■";
			Gotoxy(x + 2, y + 1);
			cout << "■▥■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		case CLOSED:
			Gotoxy(x + 2, y);
			cout << "④■■";
			Gotoxy(x + 2, y + 1);
			cout << "■■■";
			Gotoxy(x + 2, y + 2);
			cout << "■■■";
			break;
		}
	}
}

void Elevator::DrowElevatorInterface()
{
	if (elvNumber == 1)
	{
		Gotoxy(10, 4);
		cout << "＃목표층＃";

		for (int j = 1; j < 21; j++)
		{
			Gotoxy(10, j + 4);
			cout << j;
		}

		Gotoxy(10, 25);
		cout << "＃＃＃＃＃";

		for (int i = 1; i < 21; i++)
		{
			Gotoxy(12, i + 4);
			if (GetButton(i) != 0)
				cout << "★1";
			else
				cout << "   ";
		}

		Gotoxy(8, 2);
		cout << "in Elevator1";
		Gotoxy(10, 3);
		cout << GetNumber() << "명 탑승!";
	}
	else if (elvNumber == 2)
	{
		Gotoxy(70, 4);
		cout << "＃목표층＃";

		for (int j = 1; j < 21; j++)
		{
			Gotoxy(70, j + 4);
			cout << j;
		}

		Gotoxy(70, 25);
		cout << "＃＃＃＃＃";

		for (int i = 1; i < 21; i++)
		{
			Gotoxy(72, i + 4);
			if (GetButton(i) != 0)
				cout << "★2";
			else
				cout << "   ";
		}

		Gotoxy(70, 2);
		cout << "in Elevator2";
		Gotoxy(72, 3);
		cout << GetNumber() << "명 탑승!";
	}
	else if (elvNumber == 3)
	{
		Gotoxy(10, 30);
		cout << "＃목표층＃";

		for (int j = 1; j < 21; j++)
		{
			Gotoxy(10, j + 30);
			cout << j;
		}

		Gotoxy(10, 51);
		cout << "＃＃＃＃＃";

		for (int i = 1; i < 21; i++)
		{
			Gotoxy(12, i + 30);
			if (GetButton(i) != 0)
				cout << "★3";
			else
				cout << "   ";
		}

		Gotoxy(8, 27);
		cout << "in Elevator3";
		Gotoxy(10, 28);
		cout << GetNumber() << "명 탑승!";
	}
	else if (elvNumber == 4)
	{
		Gotoxy(70, 30);
		cout << "＃목표층＃";

		for (int j = 1; j < 21; j++)
		{
			Gotoxy(70, j + 30);
			cout << j;
		}

		Gotoxy(70, 51);
		cout << "＃＃＃＃＃";

		for (int i = 1; i < 21; i++)
		{
			Gotoxy(72, i + 30);
			if (GetButton(i) != 0)
				cout << "★4";
			else
				cout << "   ";
		}

		Gotoxy(70, 27);
		cout << "in Elevator4";
		Gotoxy(72, 28);
		cout << GetNumber() << "명 탑승!";
	}
}