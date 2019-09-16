#pragma once
#include <Windows.h>

// ���߿� ������� ���ʹ̶� �����

class BitMap;

class Player
{
	BitMap* m_pBitMap;
	RECT m_rectPlayerBox;
	float m_fPlayerPosX;
	float m_fPlayerPosY;
	int m_iCX;
	int m_iCY;
public:
	Player();
	~Player();
	void Init(BitMap* pBitMap, float posX, float posY, int cx, int cy);
	void Draw(HDC hdc, float posX, float posY);
	RECT GetPlayerRect();
};

