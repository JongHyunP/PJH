#pragma once
#include <Windows.h>

#define EASY_MAP_SIZE 30
#define NOMAL_MAP_SIZE 50
#define HARD_MAP_SIZE 100
#define RESETBOTTON_SIZE 10

enum MAP_LEVEL
{
	LEVEL_EASY,
	LEVEL_NOMAL,
	LEVEL_HARD,
	LEVEL_END
};

class BitMap;

class MineMap
{
private:
	BitMap* m_pMap;
	BitMap* m_pResetBotton;
	int m_MapX;
	int m_MapY;
	int m_ResetBottonX;
	int m_ResetBottonY;
	int m_MapID;
	int m_ResetBottonID;

	bool m_bResetClick;
public:
	MineMap();
	~MineMap();

	inline void SetResetBouttonNotPressed()
	{
		m_bResetClick = false;
	}

	void Init(BitMap* pMap, BitMap* pResetBotton, int mapX, int mapY, int mapID, int resetX, int resetY, int resetID);
	void Draw(HDC hdc);
	bool ResetButtonInput(POINT pt);
};

