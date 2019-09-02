#pragma once
#include <Windows.h>

#define SQUARE_LENGTH 5

class BitMap;

class Mine
{
private:
	BitMap* m_pFrontSquare;
	BitMap* m_pBackSquare;
	int m_MineX;
	int m_MineY;
	int m_MineID;

	bool m_bOpen;

public:

	inline int GetID()
	{
		return m_MineID;
	}
	inline void SetClose()
	{
		m_bOpen = false;
	}

	void Init(BitMap* pFront, BitMap* pBack, int x, int y, int id);
	void Draw(HDC hdc);
	bool Input(POINT pt);

	Mine();
	~Mine();
};

