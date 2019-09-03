#pragma once
#include <Windows.h>

#define SQUARE_LENGTH 5

enum MINE_NUM
{
	MINE_NUM_EASY = 5,
	MINE_NUM_NOMAL = 10,
	MINE_NUM_HARD = 20,
};
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
	bool m_bCheck;
public:

	inline int GetID()
	{
		return m_MineID;
	}
	inline void SetClose()
	{
		m_bOpen = false;
	}
	inline void SetOpen()
	{
		m_bOpen = true;
	}

	void Init(BitMap* pFront, BitMap* pBack, int x, int y, int id);
	void Draw(HDC hdc);
	bool Input(POINT pt);
	void FindMineNeighborhood(POINT pt);

	Mine();
	~Mine();
};

