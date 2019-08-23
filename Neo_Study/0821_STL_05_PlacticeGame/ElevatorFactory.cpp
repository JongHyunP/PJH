#include "ElevatorFactory.h"

ElevatorFactory1::ElevatorFactory1(int max, int floor = 1) : Elevator(max, floor)
{
	dContainer();
}

void ElevatorFactory1::dContainer()
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
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¡à¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	case OPENING:
	case CLOSING:
		Gotoxy(x - 3, y);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¢È¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	case CLOSED:
		Gotoxy(x - 3, y);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	}
}

void ElevatorFactory1::dDoor()
{
	dContainer();
}

void ElevatorFactory1::dButton()
{
	int i;
	for (i = 1; i < 21; i++)
	{
		Gotoxy(12, i + 6);
		if (GetButton(i) != 0)
			cout << "¡Ú";
		else
			cout << " ";
	}

	Gotoxy(8, 2);
	cout << "in Elevator1";
	Gotoxy(10, 3);
	cout << GetNumber() << "¸í Å¾½Â!";
}

ElevatorFactory2::ElevatorFactory2(int max, int floor = 1) : Elevator(max, floor)
{
	dContainer();
}

void ElevatorFactory2::dContainer()
{
	int x, y;

	x = 49;
	y = -2 * GetFloor() + 43;

	if (GetElevatorState() == MOVING_UP)
		y--;

	if (GetElevatorState() == MOVING_DOWN)
		y++;

	Gotoxy(x+2, y - 1);
	cout << "   ";
	Gotoxy(x+2, y + 3);
	cout << "   ";
	Gotoxy(x+2 + 2, y + 3);
	cout << "   ";
	Gotoxy(x+2 + 2, y - 1);
	cout << "   ";


	switch (GetDoorState())
	{
	case OPENED:
		Gotoxy(x+2, y);
		cout << "¡á¡á¡á";
		Gotoxy(x+2, y + 1);
		cout << "¡á¡à¡á";
		Gotoxy(x+2, y + 2);
		cout << "¡á¡á¡á";
		break;
	case OPENING:
	case CLOSING:
		Gotoxy(x+2, y);
		cout << "¡á¡á¡á";
		Gotoxy(x+2, y + 1);
		cout << "¡á¢È¡á";
		Gotoxy(x+2, y + 2);
		cout << "¡á¡á¡á";
		break;
	case CLOSED:
		Gotoxy(x+2, y);
		cout << "¡á¡á¡á";
		Gotoxy(x+2, y + 1);
		cout << "¡á¡á¡á";
		Gotoxy(x+2, y + 2);
		cout << "¡á¡á¡á";
		break;
	}
}


void ElevatorFactory2::dDoor()
{
	dContainer();
}

void ElevatorFactory2::dButton()
{
	int i;

	for (i = 1; i < 21; i++)
	{
		Gotoxy(71, i + 6);
		if (GetButton(i) != 0)
			cout << "¡Ú";
		else
			cout << " ";
	}

	Gotoxy(70, 2);
	cout << "in Elevator2";
	Gotoxy(72, 3);
	cout << GetNumber() << "¸í Å¾½Â!";
}


ElevatorFactory3::ElevatorFactory3(int max, int floor = 1) : Elevator(max, floor)
{
	dContainer();
}

void ElevatorFactory3::dContainer()
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
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¡à¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	case OPENING:
	case CLOSING:
		Gotoxy(x - 3, y);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¢È¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	case CLOSED:
		Gotoxy(x - 3, y);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 1);
		cout << "¡á¡á¡á";
		Gotoxy(x - 3, y + 2);
		cout << "¡á¡á¡á";
		break;
	}
}

void ElevatorFactory3::dDoor()
{
	dContainer();
}

void ElevatorFactory3::dButton()
{
	int i;
	for (i = 1; i < 21; i++)
	{
		Gotoxy(12, i + 30);
		if (GetButton(i) != 0)
			cout << "¡Ú";
		else
			cout << " ";
	}

	Gotoxy(8, 27);
	cout << "in Elevator3";
	Gotoxy(10, 28);
	cout << GetNumber() << "¸í Å¾½Â!";
}

ElevatorFactory4::ElevatorFactory4(int max, int floor = 1) : Elevator(max, floor)
{
	dContainer();
}

void ElevatorFactory4::dContainer()
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
		cout << "¡á¡á¡á";
		Gotoxy(x + 2, y + 1);
		cout << "¡á¡à¡á";
		Gotoxy(x + 2, y + 2);
		cout << "¡á¡á¡á";
		break;
	case OPENING:
	case CLOSING:
		Gotoxy(x + 2, y);
		cout << "¡á¡á¡á";
		Gotoxy(x + 2, y + 1);
		cout << "¡á¢È¡á";
		Gotoxy(x + 2, y + 2);
		cout << "¡á¡á¡á";
		break;
	case CLOSED:
		Gotoxy(x + 2, y);
		cout << "¡á¡á¡á";
		Gotoxy(x + 2, y + 1);
		cout << "¡á¡á¡á";
		Gotoxy(x + 2, y + 2);
		cout << "¡á¡á¡á";
		break;
	}
}


void ElevatorFactory4::dDoor()
{
	dContainer();
}

void ElevatorFactory4::dButton()
{
	int i;

	for (i = 1; i < 21; i++)
	{
		Gotoxy(71, i + 30);
		if (GetButton(i) != 0)
			cout << "¡Ú";
		else
			cout << " ";
	}

	Gotoxy(70, 27);
	cout << "in Elevator4";
	Gotoxy(72, 28);
	cout << GetNumber() << "¸í Å¾½Â!";
}