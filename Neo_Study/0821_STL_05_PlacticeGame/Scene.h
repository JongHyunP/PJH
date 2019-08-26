#pragma once
#include "Floor.h"
#include "ElevatorFactory.h"
#include "ElevatorManager.h"

#define FPS 3
#define PASSENGER_CREATION_COOLTIME 5

enum 
{
	SPACE_KEY_FOR_EXIT,
	RANDOM_MODE,
	INPUT_MODE,
	MENU_EXIT
};

class Scene
{
	int newFloorNum = 0;
	int destinateFloor = 0;
	int rTime = 0;
	bool canCreate = true;
	int createCountNum = PASSENGER_CREATION_COOLTIME;
public:
	Scene();
	~Scene();
	bool systemEnd = false;

	void DrowMenu();
	void DrowFloor(Floor& mFloor);
	int MenuSelect();
	int DrowInputMode();
	int DrowRandomMode();
	void Gotoxy(int x,int y);
	int KeyTest(int key); //명확한 변수명 필요.
	void CreatePeopleOnFloor(Floor& mFloor);
	void CreatePeopleDestination(Floor& mFloor);
	void RandomCreatePeople(Floor& mFloor);
};

