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
};

