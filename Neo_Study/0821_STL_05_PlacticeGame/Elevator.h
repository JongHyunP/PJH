#pragma once

class Elevator
{
protected:
	int elvMode;        // ������������ ��� (��ü��, ¦����, Ȧ����)
	int elvMaxWeight;   // ������������ �ִ� ����
	int elvNowWeight;   // ������������ ���� ����
	int elvTargetFloor; // ������������ ��ǥ��
	int elvNowFloor;    // ������������ ������
	int nowPassenger;   // ���� ž�� �°�
	int elvDirection;   // ������������ ����
public:
	Elevator();
	~Elevator();
	void ElvTargetFloorInsert(); // ������������ ��ǥ�� �Է�
	void ElvPassengerGet();      // �մ� �߰�
	void ElvPassengerGetOff();   // �մ� ����
	void RandomFloorGetPassenger(); // �������� �մ� �߰�
	void InputFloorGetPassenger(); //�Է����� �մ��߰�
	void ElvMove();                // ������������ ������
};

