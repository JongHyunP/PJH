#include "Scene.h"
#include "PublicIncludeHeader.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::DrowMenu()
{
	cout << "���������� �ùķ�����!" << endl;
	cout << "��带 �������ּ���" << endl;
	cout << "1. ���� ��� 2. �Է� ��� 3.���� : ";
	MenuSelect();
}

int Scene::MenuSelect()
{
	int inputNum = 0;
	cin >> inputNum;

	switch (inputNum)
	{
	case RANDOM_MODE:
		//�������
		system("cls");
		cout << "������� ����" << endl;
		DrowRandomMode();
		break;
	case INPUT_MODE:
		//�Է¸��
		system("cls");
		cout << "�Է¸�� ����" << endl;
		DrowInputMode();
		break;
	case MENU_EXIT:
		systemEnd = true;
		break;
	default:
		MenuSelect();
		break;
	}
	return 0;
}

void Scene::Gotoxy(int x, int y) //Ŀ�� �ű�� �Լ�
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//
//int Scene::KeyContorl() //���߿� �ʿ��ϸ� ���پ���
//{
//	char temp = _getch();
//
//	if (temp == ' ')
//	{
//		return SPACE_KEY_FOR_EXIT;
//	}
//} 

void Scene::DrowFloor(Floor& mFloor)
{
	system("cls");

	for (int i = 5; i <= 44; i += 2) //������ ������ ���� �ʿ�.
	{
		Gotoxy(31, i);
		cout << "     �ءءءءءء�";
	}

	for (int j = 1; j < 21; j++)
	{
		mFloor.Display(j);
	}
}

int Scene::DrowInputMode()
{
	system("cls");

	Floor mFloor(20);
	ElevatorFactory1 mElevator1(5, 1);
	ElevatorFactory2 mElevator2(5, 1);
	ElevatorFactory3 mElevator3(5, 1);
	ElevatorFactory4 mElevator4(5, 1);
	ElevatorManager mElevatorManager(mFloor, 20);

	DrowFloor(mFloor);

	while (1)
	{
		if (_kbhit())
		{
			CreatePeopleOnFloor(mFloor);
		}

		mElevator1.Operater();
		mElevator2.Operater();
		mElevator3.Operater();
		mElevator4.Operater();
		mElevatorManager.Operator(mElevator1);
		mElevatorManager.Operator(mElevator2);
		mElevatorManager.Operator(mElevator3);
		mElevatorManager.Operator(mElevator4);
		
	}

	return 0;
}

int Scene::DrowRandomMode()
{
	system("cls");

	srand((unsigned)time(NULL));

	Floor mFloor(20);
	ElevatorFactory1 mElevator1(5, 1);
	ElevatorFactory2 mElevator2(5, 1);
	ElevatorFactory3 mElevator3(5, 1);
	ElevatorFactory4 mElevator4(5, 1);
	ElevatorManager mElevatorManager(mFloor, 20);

	DrowFloor(mFloor);

	while (!backToMenu)
	{
		RandomCreatePeople(mFloor);

		mElevator1.Operater();
		mElevator2.Operater();
		mElevator3.Operater();
		mElevator4.Operater();
		mElevatorManager.Operator(mElevator1);
		mElevatorManager.Operator(mElevator2);
		mElevatorManager.Operator(mElevator3);
		mElevatorManager.Operator(mElevator4);

		Sleep(1000);
	}

	return 0;
}

int Scene::KeyTest(int key)
{
	int returnValue = 0;

	if (key >= 1 && key <= 20)
		returnValue = 1;

	return returnValue;
}

void Scene::CreatePeopleOnFloor(Floor& mFloor)
{
	Gotoxy(30, 49);
	cout << " ����� ��ġ�� �� :       ";
	Gotoxy(50, 49);
	cin >> newFloorNum;

	if (KeyTest(newFloorNum))
	{
		CreatePeopleDestination(mFloor);
	}
	else
	{
		newFloorNum = 0;
		CreatePeopleOnFloor(mFloor);
	}
	
}

void Scene::CreatePeopleDestination(Floor& mFloor)
{
	Gotoxy(30, 50);
	cout << " ��ǥ �� :        ";
	Gotoxy(40, 50);
	cin >> destinateFloor;

	if (KeyTest(destinateFloor))
	{
		mFloor.PushPerson(newFloorNum, destinateFloor);
		
		destinateFloor = 0;
	}
	else
	{
		destinateFloor = 0;
		CreatePeopleDestination(mFloor);
	}
}

void Scene::RandomCreatePeople(Floor& mFloor)
{
	if (canCreate)
	{
		createCountNum = PASSENGER_CREATION_COOLTIME;

		newFloorNum = rand() % 20 + 1;
		destinateFloor = rand() % 20 + 1;

		if (newFloorNum != destinateFloor)
		{
			mFloor.PushPerson(newFloorNum, destinateFloor);

			destinateFloor = 0;
			canCreate = false;
		}
	}
	else
	{
		if (createCountNum == 0)
		{
			canCreate = true;
		}
		else 
		{
			if (createCountNum > 0)
			{
				createCountNum--;
			}
		}
	}
}