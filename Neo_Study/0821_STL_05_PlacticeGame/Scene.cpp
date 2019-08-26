#include "Scene.h"
#include "PublicIncludeHeader.h"

Scene::Scene()
{
	pFloor = nullptr;
	pElvManager = nullptr;
}


Scene::~Scene()
{
	delete pFloor;
	delete pElvManager;
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
		StartRandomMode();
		break;
	case INPUT_MODE:
		//�Է¸��
		system("cls");
		cout << "�Է¸�� ����" << endl;
		StartInputMode();
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

void Scene::Initialized()
{
	pFloor = new Floor(MAX_FLOOR);

	pElvManager = new ElevatorManager(*pFloor, MAX_FLOOR);

	vectorElevator.reserve(COUNT);

	for (int i = 0; i < COUNT; i++)
	{
		vectorElevator.push_back(new Elevator(MAX_NUMBER_OF_PROPLE, FIRST_FLOOR, i + 1));
	}

	DrowFloor(*pFloor);
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

void Scene::StartInputMode()
{
	system("cls");

	Initialized();

	InputModeUpdate();
}

void Scene::StartRandomMode()
{
	system("cls");

	srand((unsigned)time(NULL));

	Initialized();

	RandomModeUpdate();

}

void Scene::RandomModeUpdate()
{
	while (!backToMenu)
	{
		RandomCreatePeople(*pFloor);

		for (vector< Elevator*>::iterator iter = vectorElevator.begin(); iter != vectorElevator.end(); ++iter)
		{
			(*iter)->Operater();
			(*pElvManager).Operator(*iter);
		}
		Sleep(1000);
	}
}

void Scene::InputModeUpdate()
{
	while (!backToMenu)
	{
		if (_kbhit())
		{
			CreatePeopleOnFloor(*pFloor);
		}

		for (vector< Elevator*>::iterator iter = vectorElevator.begin(); iter != vectorElevator.end(); ++iter)
		{
			(*iter)->Operater();
			(*pElvManager).Operator(*iter);
		}

		Sleep(1000);
	}
}

int Scene::IsNumberInFloor(int num)
{
	int returnValue = 0;

	if (num >= 1 && num <= 20)
		returnValue = 1;

	return returnValue;
}

void Scene::CreatePeopleOnFloor(Floor& mFloor)
{
	Gotoxy(30, 49);
	cout << " ����� ��ġ�� �� :       ";
	Gotoxy(50, 49);
	cin >> newFloorNum;

	if (IsNumberInFloor(newFloorNum))
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

	if (IsNumberInFloor(destinateFloor))
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