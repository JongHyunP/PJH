#pragma once

class Elevator
{
protected:
	int elvMode;        // 엘레베이터의 모드 (전체층, 짝수층, 홀수층)
	int elvMaxWeight;   // 엘레베이터의 최대 하중
	int elvNowWeight;   // 엘레베이터의 현재 무게
	int elvTargetFloor; // 엘레베이터의 목표층
	int elvNowFloor;    // 엘레베이터의 현재층
	int nowPassenger;   // 현재 탑승 승객
	int elvDirection;   // 엘레베이터의 방향
public:
	Elevator();
	~Elevator();
	void ElvTargetFloorInsert(); // 엘레베이터의 목표층 입력
	void ElvPassengerGet();      // 손님 추가
	void ElvPassengerGetOff();   // 손님 빼기
	void RandomFloorGetPassenger(); // 랜덤으로 손님 추가
	void InputFloorGetPassenger(); //입력으로 손님추가
	void ElvMove();                // 엘레베이터의 움직임
};

