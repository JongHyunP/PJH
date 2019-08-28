#include "WordRect.h"



WordRect::WordRect()
{
}


WordRect::~WordRect()
{
}

void WordRect::MakeRectangle(HDC hdc,int Left, int Top, int Right, int Bottom)
{
	MoveToEx(hdc, Left, Top,NULL);
	LineTo(hdc, Right, Top);

	MoveToEx(hdc, Right, Top, NULL);
	LineTo(hdc, Right, Bottom);

	MoveToEx(hdc, Right, Bottom, NULL);
	LineTo(hdc, Left, Bottom);

	MoveToEx(hdc, Left, Bottom, NULL);
	LineTo(hdc, Left, Top);

	rLeft = Left;
	rRight = Right;
	rTop = Top;
	rBottom = Bottom;

}

bool WordRect::RectCrush(WordRect & rect1, WordRect & rect2)
{
	if (abs(rect1.rLeft - rect2.rLeft) <=0)
	{
		return true;
	}
	if (abs(rect1.rTop - rect2.rTop) <= 0)
	{
		return true;
	}
	if (abs(rect1.rRight - rect2.rRight) <= 0)
	{
		return true;
	}
	if (abs(rect1.rBottom - rect2.rBottom) <= 0)
	{
		return true;
	}

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
	TextOut(hdc,(rect.rRight-rect.rLeft)/2+ 2,(rect.rBottom-rect.rTop)/2 +rect.rTop, TEXT("asdddssd"), 8);
}


