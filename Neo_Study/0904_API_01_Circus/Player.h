#pragma once
#include <Windows.h>

class BitMap;

class Player
{
private:
	BitMap* m_pPlayer;
	int m_PlayerPosX;
	int m_PlayerPosY;
public:
	void Init(BitMap* pPlayer, int posX, int posY);
	void Draw(HDC hdc);
};

