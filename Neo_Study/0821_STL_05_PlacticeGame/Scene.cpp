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
	cout << "1. ���� ��� 2. �Է� ��� : ";
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
		//�������
		cout << "������� ����" << endl;
		break;
	case INPUT_MODE:
		//�Է¸��
		cout << "�Է¸�� ����" << endl;
		break;
	default:
		MenuSelect();
		break;
	}
}

void Scene::Gotoxy(int x, int y) //Ŀ�� �ű�� �Լ�
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
	cout << "�����̽��� ������ �޴���" << endl;

	while (KeyContorl()==EMPTY)
	{	

	}
}
