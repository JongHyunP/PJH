#include "Floor.h"

Floor::Floor(int floor)
{
	UpPerson = new Queue[floor + 1];
	DownPerson = new Queue[floor + 1];
}

Floor::~Floor()
{
	delete UpPerson;
	delete DownPerson;
}

void Floor::PushPerson(int floor, int destinate)
{
	if (destinate > floor)
		UpPerson[floor].Push(destinate);
	else
		DownPerson[floor].Push(destinate);

	Display(floor);
}

int Floor::PopPerson(int floor, int direction)
{
	int temp;
	if (direction == 1)
		temp = UpPerson[floor].Pop();
	else
		temp = DownPerson[floor].Pop();

	Display(floor);
	return temp;
}

int Floor::GetPersonNumber(int floor, int direction)
{
	int temp;
	if (direction == 1)
		temp = UpPerson[floor].GetNumber();
	else
		temp = DownPerson[floor].GetNumber();

	return temp;
}

int Floor::GetButton(int floor)
{
	int returnValue = 0;

	if (GetPersonNumber(floor, 1) != 0)
		returnValue = 1;

	if (GetPersonNumber(floor, -1) != 0)
		returnValue = 1;

	return returnValue;
}

void Floor::Display(int floor)
{
	Gotoxy(36, -2 * floor + 44);
	cout << "¡ã:" << GetPersonNumber(floor, 1);
	Gotoxy(41, -2 * floor + 44);
	cout << floor << "F";
	Gotoxy(45, -2 * floor + 44);
	cout << "¡ä:" << GetPersonNumber(floor, -1);

}

void Floor::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}