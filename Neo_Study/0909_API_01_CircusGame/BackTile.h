#pragma once
#include <Windows.h>

class BitMap;
class BackTile
{
private:
	BitMap* m_pBitMap;
	int m_iX;
	int m_iY;
	int m_iCX;
	int m_iCY;
public:
	void Init(BitMap* pBitMap , int x , int y , int cx , int cy);
	void Draw(HDC hdc, int PlayerX);
	void Update(int moveX);
	BackTile();
	~BackTile();
};

 