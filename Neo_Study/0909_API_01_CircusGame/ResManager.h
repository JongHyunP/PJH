#pragma once
#include <Windows.h>
#include <map>
#include <string>
using namespace std;

#define WIN_X 800
#define WIN_Y 600
#define MAX_SIZE 800

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

class Player;

class ResManager
{
private:
	map<string, BitMap*>	m_mapBitMap;
	HDC						m_hMemDC;
	HBITMAP					m_hBitMap;
	HBITMAP					m_hOldBitMap;
	Player*					m_pPlayer;
public:
	int						m_iDisplayX;
	void Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc,int x);
	BitMap* GetBitMap(string strFileName);
	void Release();
	ResManager();
	~ResManager();
};

