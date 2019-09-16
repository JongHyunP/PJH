#pragma once
#include <Windows.h>

class BitMap;

class Object
{
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	int m_iCX;
	int m_iCY;
	int m_iId;

public:
	Object();
	~Object();
	void Init(BitMap* pBitMap, int x, int y, int cx, int cy,int id);
	void Draw(HDC hdc, bool bTrans);
	bool Input(POINT pt);
	int GetObjectX()
	{
		return m_iX;
	}
	int GetObjectY()
	{
		return m_iY;
	}
};

