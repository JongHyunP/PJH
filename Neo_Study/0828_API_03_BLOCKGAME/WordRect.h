#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <list>

using namespace std;

enum WORD_TYPE { NOMAL_WORD , ITEM_WORD};
enum WORD_STATE { ON, OFF};

class WordRect
{
	WORD_TYPE wordType;
	WORD_STATE wordState;
	int wordX;
	int wordY;
	int wordSpeed;
	const TCHAR* typingWord;
	int randomX;
public:
	WordRect(WORD_TYPE type,int x,int y,int speed,TCHAR* word);
	~WordRect();
	void Update();
	void Render(HDC hdc);
	void RandomXPostion();
	void MoveDown();
	void IsCorrect();
};

