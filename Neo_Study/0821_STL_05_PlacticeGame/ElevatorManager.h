#pragma once
class ElevatorManager
{
public:
	ElevatorManager();
	~ElevatorManager();

	void ElvTargetFloorInsert(); // ������������ ��ǥ�� �Է�
	void ElvPassengerGet();      // �մ� �߰�
	void ElvPassengerGetOff();   // �մ� ����
	void RandomFloorGetPassenger(); // �������� �մ� �߰�
	void InputFloorGetPassenger(); //�Է����� �մ��߰�
	void ElvMove();                // ������������ ������
};

