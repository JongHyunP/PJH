#pragma once
#include <Windows.h>
#include <vector>

class WordRect
{
	int rLeft=50;
	int rRight=150;
	int rTop=50;
	int rBottom=100;
	int rSpeed=0;
	TCHAR* str;
	
public:
	WordRect();
	~WordRect();
	void MakeRectangle(HDC hdc);
	bool RectCrush(WordRect& rect1, WordRect& rect2);
	void RectMove(WordRect& rect, int speed);
	void MakeWordText(HDC hdc, WordRect& rect);
};

