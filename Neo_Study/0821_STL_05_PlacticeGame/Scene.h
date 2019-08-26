#pragma once
#include "Floor.h"
#include "ElevatorManager.h"

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
	vector<Elevator*> vectorElevator;
	Floor* pFloor;
	ElevatorManager* pElvManager;

	int newFloorNum = 0;
	int destinateFloor = 0;
	int rTime = 0;
	bool canCreate = true;
	int createCountNum = PASSENGER_CREATION_COOLTIME;
public:
	Scene();
	~Scene();
	void Initialized();
	bool systemEnd = false;
	bool backToMenu = false;
	void DrowMenu();
	void DrowFloor(Floor& mFloor);
	int MenuSelect();
	void StartInputMode();
	void StartRandomMode();
	void RandomModeUpdate();
	void InputModeUpdate();
	void Gotoxy(int x,int y);
	int IsNumberInFloor(int key);
	void CreatePeopleOnFloor(Floor& mFloor);
	void CreatePeopleDestination(Floor& mFloor);
	void RandomCreatePeople(Floor& mFloor);
};

