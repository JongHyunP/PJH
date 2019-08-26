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
	cout << "엘레베이터 시뮬레이터!" << endl;
	cout << "모드를 선택해주세요" << endl;
	cout << "1. 랜덤 모드 2. 입력 모드 3.종료 : ";
	MenuSelect();
}

int Scene::MenuSelect()
{
	int inputNum = 0;
	cin >> inputNum;

	switch (inputNum)
	{
	case RANDOM_MODE:
		//랜덤모드
		system("cls");
		cout << "랜덤모드 시작" << endl;
		StartRandomMode();
		break;
	case INPUT_MODE:
		//입력모드
		system("cls");
		cout << "입력모드 시작" << endl;
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


void Scene::Gotoxy(int x, int y) //커서 옮기는 함수
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//
//int Scene::KeyContorl() //나중에 필요하면 갖다쓰기
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

	for (int i = 5; i <= 44; i += 2) //적절한 변수명 설정 필요.
	{
		Gotoxy(31, i);
		cout << "     ※※※※※※※";
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
	cout << " 사람을 배치할 층 :       ";
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
	cout << " 목표 층 :        ";
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