#include "WordRect.h"

//srand((unsigned)time(nullptr));

WordRect::WordRect(WORD_TYPE type, int x, int y, int speed, TCHAR* word)
{
	wordType = type;
	wordState = ON;
	wordX = x;
	wordY = y;
	wordSpeed = speed;
	typingWord = word;
}


WordRect::~WordRect()
{
}

void WordRect::Update()  
{
	if (wordState == ON)
	{
		if (wordType == NOMAL_WORD)
		{
			MoveDown();
		}

		if (wordType == ITEM_WORD)
		{
			MoveDown();
		}
	}

	if (wordState == OFF)
	{
		if (wordType == NOMAL_WORD)
		{
			MoveDown();
		}

		if (wordType == ITEM_WORD)
		{
			MoveDown();
		}
	}
}

void WordRect::Render(HDC hdc) // 그려주는 역할
{
	RandomXPostion();

	Rectangle(hdc, wordX - 5, wordY - 5, wordX + lstrlen(typingWord) + 50, wordY + 25);
	TextOut(hdc, wordX, wordY, typingWord, lstrlen(typingWord));
}

void WordRect::RandomXPostion()
{
	randomX = rand() % 1160 + 20;
	
	wordX = randomX;
}

void WordRect::MoveDown()
{
	wordY -= 1;
}

void WordRect::IsCorrect()
{
	typingWord = TEXT(" ");
}
