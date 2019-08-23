#pragma once
#include "Floor.h"
#include "ElevatorFactory.h"
#include "ElevatorManager.h"

#define FPS 3

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
public:
	Scene();
	~Scene();
	bool systemEnd = false;

	void DrowMenu();
	void DrowFloor(Floor& mFloor);
	int MenuSelect();
	int DrowInputMode();
	int DrowRandomMode();
	int KeyContorl();
	void Gotoxy(int x,int y);
	void InitialTargetFloorDisplay();
	//int KeyTest(char key);
	int KeyTest2(int key);
	//void DisplayKey(char key1, char key2);
	void CreatePeopleOnFloor(Floor& mFloor);
	void CreatePeopleDestination(Floor& mFloor);
};

