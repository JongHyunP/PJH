#pragma once
#include <Windows.h>
#include "ResourceManager.h"

#define CARD_WIDGHT 145
#define CARD_HIGHT 235

enum CARD_STATE {
	CARD_WAIT,
	CARD_SELECT_ONE,
	CARD_WRONG_CHOICE
};

class Card
{
	int cardX;
	int cardY;
	int cardID;

public:
	Card();
	~Card();
	
	void Init();
	void Input();
	void Draw();
};

