#pragma once

//class Elevator
//{
//protected:
//	int elvMode;        // 엘레베이터의 모드 (전체층, 짝수층, 홀수층)
//	int elvMaxWeight;   // 엘레베이터의 최대 하중
//	int elvNowWeight;   // 엘레베이터의 현재 무게
//	int elvTargetFloor; // 엘레베이터의 목표층
//	int elvNowFloor;    // 엘레베이터의 현재층
//	int nowPassenger;   // 현재 탑승 승객
//	int elvDirection;   // 엘레베이터의 방향
//public:
//	Elevator();
//	~Elevator();
//	void ElvTargetFloorInsert(); // 엘레베이터의 목표층 입력
//	void ElvPassengerGet();      // 손님 추가
//	void ElvPassengerGetOff();   // 손님 빼기
//	void RandomFloorGetPassenger(); // 랜덤으로 손님 추가
//	void InputFloorGetPassenger(); //입력으로 손님추가
//	void ElvMove();                // 엘레베이터의 움직임
//};

#include "PublicIncludeHeader.h"
#include "QUEUE.h"
#include "FLOOR.h"

enum elvOver { NO, FULL, OVER };
enum elvDoor { CLOSED, CLOSING, OPENED, OPENING };
enum elvElevator { STOP, MOVING_UP, MOVING_DOWN };

class Elevator
{
	Queue Person;
	int itsFloor;
	int maxPerson;
	int weightLimit;
	elvDoor doorState;
	elvElevator elevatorState;
	int itsDirection;
	long itsTimer;
	int itsFlag;
	int* itsButton;

	virtual void vElevator() = 0;
	virtual void vDoor() = 0;
	virtual void vInterface() = 0;
public:
	Elevator(int max, int floor);
	~Elevator();
	void Operater();
	void MoveUp();
	void MoveDown();
	void Open();
	void Close();
	elvOver IsitFull();
	elvDoor GetDoorState();
	elvElevator GetElevatorState();
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
};