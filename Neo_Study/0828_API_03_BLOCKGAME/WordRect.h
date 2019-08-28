#pragma once
#include <Windows.h>
#include <vector>

class WordRect
{
	int rLeft=0;
	int rRight=0;
	int rTop=0;
	int rBottom=0;
	int rSpeed=0;
	TCHAR* str;
	
public:
	WordRect();
	~WordRect();
	void MakeRectangle(HDC hdc,int Left, int Top, int Right, int Bottom);
	bool RectCrush(WordRect& rect1, WordRect& rect2);
	void RectMove(WordRect& rect, int speed);
	void MakeWordText(HDC hdc, WordRect& rect);
};

