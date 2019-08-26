#pragma once
#include "Elevator.h"
#include "Floor.h"

enum DECIDE_DIRECTION { DECIDE_DOWN = -1, DECIDE_UP = 1 };


class ElevatorManager
{
	Floor* pFloor;
	Elevator* pElevator;
public:
	int DecideOpen();
	int DecideMoving();
	int DecideOperate();
	int DecideDirection();
	int maxFloor;

	ElevatorManager(Floor& rFloor, int max);
	~ElevatorManager();
	void Operator(Elevator* rElevator);
};