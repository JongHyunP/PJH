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
	cout << "엘레베이터 시뮬레이터!" << endl;
	cout << "모드를 선택해주세요" << endl;
	cout << "1. 랜덤 모드 2. 입력 모드 : ";
	MenuSelect();
}

void Scene::MenuSelect()
{
	system("cls");

	int inputNum = 0;
	cin >> inputNum;

	switch (inputNum)
	{
	case RANDOM_MODE:
		//랜덤모드
		cout << "랜덤모드 시작" << endl;
		break;
	case INPUT_MODE:
		//입력모드
		cout << "입력모드 시작" << endl;
		break;
	default:
		MenuSelect();
		break;
	}
}

void Scene::Gotoxy(int x, int y) //커서 옮기는 함수
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int Scene::KeyContorl()
{
	char temp = _getch();

	if (temp == ' ')
	{
		return EMPTY;
	}
}

void Scene::DrowBuilding()
{
	cout << "스페이스바 누르면 메뉴로" << endl;

	while (KeyContorl()==EMPTY)
	{	

	}
}
