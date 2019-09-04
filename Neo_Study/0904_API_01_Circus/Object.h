#pragma once
#include <Windows.h>

class BitMap;

class Object
{
private:
	BitMap* m_pObject;
	int m_ObjectPosX;
	int m_ObjectPosY;
public:
	void Init(BitMap* pObject, int posX, int posY);
	void Draw(HDC hdc);
};

