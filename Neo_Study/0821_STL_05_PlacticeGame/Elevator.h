#pragma once

//class Elevator
//{
//protected:
//	int elvMode;        // ������������ ��� (��ü��, ¦����, Ȧ����)
//	int elvMaxWeight;   // ������������ �ִ� ����
//	int elvNowWeight;   // ������������ ���� ����
//	int elvTargetFloor; // ������������ ��ǥ��
//	int elvNowFloor;    // ������������ ������
//	int nowPassenger;   // ���� ž�� �°�
//	int elvDirection;   // ������������ ����
//public:
//	Elevator();
//	~Elevator();
//	void ElvTargetFloorInsert(); // ������������ ��ǥ�� �Է�
//	void ElvPassengerGet();      // �մ� �߰�
//	void ElvPassengerGetOff();   // �մ� ����
//	void RandomFloorGetPassenger(); // �������� �մ� �߰�
//	void InputFloorGetPassenger(); //�Է����� �մ��߰�
//	void ElvMove();                // ������������ ������
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