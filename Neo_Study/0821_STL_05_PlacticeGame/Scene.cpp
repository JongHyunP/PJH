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
	for (int i = 1; i < 21; i++)
	{
		mFloor.Display(i);
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

	InitialTargetFloorDisplay();

	//char key, firstInput = 0;

	DrowFloor(mFloor);

	while (1)
	{
		if (_kbhit())
		{
			CreatePeopleOnFloor(mFloor);
		}
		/*if (_kbhit())
		{
			key = _getch();

			if (KeyTest(key))
			{
				if (firstInput == 0)
				{
					firstInput = key;
					DisplayKey(key, 0);
				}
				else
				{
					mFloor.PushPerson(firstInput - '0', key - '0');
					DisplayKey(firstInput, key);
					firstInput = 0;
				}
			}
		}*/

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

	InitialTargetFloorDisplay();

	//char key, firstInput = 0;

	DrowFloor(mFloor);

	while (1)
	{
		
		newFloorNum = rand() % 20 + 1;
		destinateFloor = rand() % 20 + 1;

		if (newFloorNum != destinateFloor)
		{
			mFloor.PushPerson(newFloorNum, destinateFloor);

			destinateFloor = 0;
		}
		
	

		mElevator1.Operater();
		mElevator2.Operater();
		mElevator3.Operater();
		mElevator4.Operater();
		mElevatorManager.Operator(mElevator1);
		mElevatorManager.Operator(mElevator2);
		mElevatorManager.Operator(mElevator3);
		mElevatorManager.Operator(mElevator4);

		Sleep(1000 / FPS);
	}

	return 0;
}

void Scene::InitialTargetFloorDisplay()
{
	system("cls");

	int i, j;
	for (i = 5; i <= 44; i += 2)
	{
		Gotoxy(31, i);
		cout << "     �ءءءءءء�";
	}

	int x = 10;

	for (j = 0; j < 2; j++)
	{
		Gotoxy(x, 4);
		cout << "����ǥ����";

		Gotoxy(x, 25);
		cout << "����������";

		Gotoxy(x, 30);
		cout<< "����ǥ����";

		Gotoxy(x, 51);
		cout << "����������";

		for (i = 1; i < 21; i++)
		{
			Gotoxy(x, i + 4);
			cout << i;
			Gotoxy(x, i + 30);
			cout << i;
		}
		x = 70;
	}

	
}

//
//int Scene::KeyTest(char key)
//{
//	int returnValue = 0;
//
//	if (key >= '1' && key <= '20')
//		returnValue = 1;
//
//	return returnValue;
//}

int Scene::KeyTest2(int key)
{
	int returnValue = 0;

	if (key >= 1 && key <= 20)
		returnValue = 1;

	return returnValue;
}

//void Scene::DisplayKey(char key1 = 0, char key2 = 0)
//{
//	Gotoxy(30, 49);
//	cout << " ����� ��ġ�� �� : ";
//	if (key1 == 0)
//		cout << "?";
//	else
//		cout << key1;
//
//	Gotoxy(30, 50);
//	cout << " ��ǥ �� : ";
//	if (key2 == 0)
//		cout << "?";
//	else
//		cout << key2;
//}

void Scene::CreatePeopleOnFloor(Floor& mFloor)
{
	Gotoxy(30, 49);
	cout << " ����� ��ġ�� �� :       ";
	Gotoxy(50, 49);
	cin >> newFloorNum;

	if (KeyTest2(newFloorNum))
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

	if (KeyTest2(destinateFloor))
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