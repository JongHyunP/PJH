#include "WordRect.h"



WordRect::WordRect()
{
}


WordRect::~WordRect()
{
}

void WordRect::MakeRectangle(HDC hdc)
{
	MoveToEx(hdc, rLeft, rTop,NULL);
	LineTo(hdc, rRight, rTop);

	MoveToEx(hdc, rRight, rTop, NULL);
	LineTo(hdc, rRight, rBottom);

	MoveToEx(hdc, rRight, rBottom, NULL);
	LineTo(hdc, rLeft, rBottom);

	MoveToEx(hdc, rLeft, rBottom, NULL);
	LineTo(hdc, rLeft, rTop);

}

bool WordRect::RectCrush(WordRect & rect1, WordRect & rect2)
{
	
	return false;
}

void WordRect::RectMove(WordRect&  rect , int speed)
{
	rect.rSpeed = speed;

	rect.rTop += rect.rSpeed;
	rect.rBottom += rect.rSpeed;
}

void WordRect::MakeWordText(HDC hdc,WordRect& rect)
{
	MakeRectangle(hdc);
	TextOut(hdc,(rect.rRight-rect.rLeft)/2+ 2,(rect.rBottom-rect.rTop)/2 +rect.rTop, buf, lstrlen(buf));
}

void WordRect::LoadWord(HWND hWnd,HDC hdc) // 처음시작될때 읽자
{
	//line_vector = split(line, ' ');

	hFile = CreateFile(stt, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		ReadFile(hFile, buf, 1024, &dwRead, NULL);
		CloseHandle(hFile);
		InvalidateRect(hWnd, NULL, TRUE);
	}
}


