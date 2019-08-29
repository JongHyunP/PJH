#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class WordRect
{
	int rLeft=50;
	int rRight=150;
	int rTop=50;
	int rBottom=100;
	int rSpeed=0;
	TCHAR* str;
	HANDLE hFile;
	DWORD dwRead;
	const TCHAR *stt = TEXT("Test.txt");
	TCHAR buf[1025];
	vector<string> line_vector;
public:
	WordRect();
	~WordRect();
	void MakeRectangle(HDC hdc);
	bool RectCrush(WordRect& rect1, WordRect& rect2);
	void RectMove(WordRect& rect, int speed);
	void MakeWordText(HDC hdc, WordRect& rect);
	void LoadWord(HWND hWnd, HDC hdc);
	
};

