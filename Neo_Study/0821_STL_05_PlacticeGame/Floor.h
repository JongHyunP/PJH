#pragma once
#include"Queue.h"
#include "PublicIncludeHeader.h"

#define MAX_FLOOR 20
#define FIRST_FLOOR 1

enum FloorDirection { DOWN = -1 , UP = 1};

class Floor //�ö󰡴� ���, �������� ����� ť�� ����
{
	Queue* UpPerson;
	Queue* DownPerson;
public:
	Floor(int floor);
	~Floor();
	void PushPerson(int floor, int destinate);
	int PopPerson(int floor, int direction);
	int GetPersonNumber(int floor, int direction);
	int GetButton(int floor);
	void Display(int floor);
	void Gotoxy(int x, int y);
};
