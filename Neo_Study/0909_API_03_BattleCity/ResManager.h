#pragma once
#include <Windows.h>
#include <map>
#include <string>

using namespace std;
#define WIN_X 800
#define WIN_Y 600
#define MAX_SIZE 800

enum RES_TYPE_ETC
{
	MISSILE,
	PLAYER_ICON,
	ENEMY_ICON,
	STAGE_ICON,
	RES_TYPE_ETC_END
};

enum RES_TYPE_PLAYER
{
	PLAYER_DOWN_00,
	PLAYER_DOWN_01,
	PLAYER_LEFT_00,
	PLAYER_LEFT_01,
	PLAYER_RIGHT_00,
	PLAYER_RIGHT_01,
	PLAYER_UP_00,
	PLAYER_UP_01,
	PLAYER_SHIELD_00,
	PLAYER_SHIELD_01,
	RES_TYPE_PLAYER_END
};

enum RES_TYPE_BLOCK
{
	BLOCK_00,
	BLOCK_01,
	BLOCK_02,
	BLOCK_03,
	BLOCK_04,
	BLOCK_05,
	BLOCK_06,
	BLOCK_07,
	BLOCK_08,
	BLOCK_09,
	BLOCK_10,
	BLOCK_11,
	BLOCK_12,
	BLOCK_13,
	BLOCK_14,
	BLOCK_15,
	BLOCK_16,
	RES_TYPE_BLOCK_END
};

enum RES_TYPE_ENEMY
{
	ENEMY_DOWN_01,
	ENEMY_DOWN_02,
	ENEMY_DOWN_03,
	ENEMY_LEFT_01,
	ENEMY_LEFT_02,
	ENEMY_LEFT_03,
	ENEMY_RIGHT_01,
	ENEMY_RIGHT_02,
	ENEMY_RIGHT_03,
	ENEMY_UP_01,
	ENEMY_UP_02,
	ENEMY_UP_03,
	RES_TYPE_ENEMY_END
};

enum RES_TYPE_EXPLOSION
{
	//나중에 추가
};


class BitMap;

class ResManager
{
private:
	map<string, BitMap*>	m_mapBitMap;
	HDC						m_hMemDC;
	HBITMAP					m_hBitMap;
	HBITMAP					m_hOldBitMap;

public:
	ResManager();
	~ResManager();
	void Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc);
	BitMap* GetBitMap(string strFileName);
	void Release();
};

