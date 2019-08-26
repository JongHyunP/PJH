#pragma once

#include "PublicIncludeHeader.h"
#include "QUEUE.h"
#include "FLOOR.h"

#define MAX_NUMBER_OF_PROPLE 5
#define COUNT 4

enum ELEVATOR_FULL { NO, FULL, OVER };
enum ELEVATOR_DOOR { CLOSED, CLOSING, OPENED, OPENING };
enum ELEVATOR_STATE { STOP, MOVING_UP, MOVING_DOWN };



class Elevator
{
	Queue Person;
	int elvNumber;
	int itsFloor;
	int maxPerson;
	int weightLimit;
	ELEVATOR_DOOR doorState;
	ELEVATOR_STATE elevatorState;
	int itsDirection;
	long itsTimer;
	int itsFlag;

public:
	Elevator(int max, int floor,int elvNum);
	~Elevator();
	void Operater();
	void MoveUp();
	void MoveDown();
	void Open();
	void Close();
	ELEVATOR_FULL IsitFull();
	ELEVATOR_DOOR GetDoorState();
	ELEVATOR_STATE GetElevatorState();
	int GetNumber();
	int GetDirection();
	int GetFloor();
	void SetDirection(int n) { itsDirection = n; };
	int GetFlag();
	void SetFlag(int newFlag);
	void GetIn(Floor& rFloor);
	void GetOut(Floor& rFloor);
	int GetButton(int floor);
	void Gotoxy(int x, int y);
	void DrowElevator();
	void DrowElevatorInterface();
};