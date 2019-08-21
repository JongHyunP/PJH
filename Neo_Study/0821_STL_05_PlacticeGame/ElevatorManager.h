#pragma once
class ElevatorManager
{
public:
	ElevatorManager();
	~ElevatorManager();

	void ElvTargetFloorInsert(); // 엘레베이터의 목표층 입력
	void ElvPassengerGet();      // 손님 추가
	void ElvPassengerGetOff();   // 손님 빼기
	void RandomFloorGetPassenger(); // 랜덤으로 손님 추가
	void InputFloorGetPassenger(); //입력으로 손님추가
	void ElvMove();                // 엘레베이터의 움직임
};

