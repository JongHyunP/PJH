#include "ElevatorFactory.h"
//max 인자 명확히 해줘야함. 인원수 맥스 뜻임.
ElevatorFactory1::ElevatorFactory1(int max, int floor = 1) : Elevator(max, floor)
{
	vElevator();
}

void ElevatorFactory1::vElevator()
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

void ElevatorFactory1::vDoor()
{
	vElevator();
}

void ElevatorFactory1::vInterface()
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

ElevatorFactory2::ElevatorFactory2(int max, int floor = 1) : Elevator(max, floor)
{
	vElevator();
}

void ElevatorFactory2::vElevator()
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
		cout << "②■■";
		Gotoxy(x+2, y + 1);
		cout << "■□■";
		Gotoxy(x+2, y + 2);
		cout << "■■■";
		break;
	case OPENING:
	case CLOSING:
		Gotoxy(x+2, y);
		cout << "②■■";
		Gotoxy(x+2, y + 1);
		cout << "■▥■";
		Gotoxy(x+2, y + 2);
		cout << "■■■";
		break;
	case CLOSED:
		Gotoxy(x+2, y);
		cout << "②■■";
		Gotoxy(x+2, y + 1);
		cout << "■■■";
		Gotoxy(x+2, y + 2);
		cout << "■■■";
		break;
	}
}


void ElevatorFactory2::vDoor()
{
	vElevator();
}

void ElevatorFactory2::vInterface()
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


ElevatorFactory3::ElevatorFactory3(int max, int floor = 1) : Elevator(max, floor)
{
	vElevator();
}

void ElevatorFactory3::vElevator()
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

void ElevatorFactory3::vDoor()
{
	vElevator();
}

void ElevatorFactory3::vInterface()
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

ElevatorFactory4::ElevatorFactory4(int max, int floor = 1) : Elevator(max, floor)
{
	vElevator();
}

void ElevatorFactory4::vElevator()
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


void ElevatorFactory4::vDoor()
{
	vElevator();
}

void ElevatorFactory4::vInterface()
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