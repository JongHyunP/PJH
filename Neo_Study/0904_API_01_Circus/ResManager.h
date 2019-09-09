#pragma once
#include <Windows.h>
#include <map>
#include <string>

using namespace std;

enum RES_ENUM_TYPE
{
	UI,
	BACKGROUND,
	PLAYER,
	OBJECT,
	RES_ENUM_TYPE_END
};
enum RES_TYPE_UI
{
	STAR_01,
	STAR_02,
	LIFE_ICON,
	MITER,
	RES_TYPE_UI_END
};
enum RES_TYPE_BACKGROUND
{
	GRASS_FIELD,
	ELEPHANT,
	CROWD_01,
	CROWD_02,
	RES_TYPE_BACKGROUND_END
};
enum RES_TYPE_PLAYER
{
	PLAYER_IDLE,
	PLAYER_RUN,
	PLAYER_JUMP,
	PLAYER_WIN_01,
	PLAYER_WIN_02,
	PLAYER_DIE,
	RES_TYPE_PLAYER_END
};
enum RES_TYPE_OBJECT
{
	END_BOX,
	CASH,
	ENEMY_CUP_01,
	ENEMY_CUP_02,
	ENEMY_RING_OFF_BACK,
	ENEMY_RING_OFF_FRONT,
	ENEMY_RING_ON_BACK,
	ENEMY_RING_ON_FRONT,
	RES_TYPE_OBJECT_END
};

class BitMap;

class ResManager
{
private:
	map<string, BitMap*> m_mapBitMap;
	HDC m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;

	BitMap*		m_pBitMapUi[RES_TYPE_UI_END];
	BitMap*		m_pBitMapBackground[RES_TYPE_BACKGROUND_END];
	BitMap*		m_pBitMapPlayer[RES_TYPE_PLAYER_END];
	BitMap*		m_pBitMapObject[RES_TYPE_OBJECT_END];
public:
	void Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc);
	BitMap* GetBitMap(int index, RES_ENUM_TYPE num);
	void Release();
	ResManager();
	~ResManager();
};

