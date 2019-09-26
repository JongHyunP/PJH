#pragma once
#include <Windows.h>

class BitMap;

class BoardTile
{
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
public:
	void Init(BitMap* pBitMap, int x, int y);
	void Draw(HDC hdc);
	void ChangeBitMap(BitMap* pBitMap);
	BoardTile();
	~BoardTile();
};

