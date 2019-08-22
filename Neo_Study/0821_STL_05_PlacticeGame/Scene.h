#pragma once

enum 
{
	EMPTY,
	RANDOM_MODE,
	INPUT_MODE
};

class Scene
{
	int map[30][30];
public:
	Scene();
	~Scene();
	void DrowMenu();
	void MenuSelect();
	void DrowBuilding();
	int KeyContorl();
	void Gotoxy(int x,int y);
};

