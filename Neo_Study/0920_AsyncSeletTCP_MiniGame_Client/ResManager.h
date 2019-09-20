#pragma once
#include <Windows.h>
#include <map>
#include <string>
using namespace std;

#define WIN_X 1024
#define WIN_Y 768
#define MAX_SIZE 1024

enum RES_TYPE_BOARD
{
	BORAD_BLACK_PAWN,
	BORAD_BLACK_KNIGHT,
	BORAD_BLACK_BISHOP,
	BORAD_BLACK_ROOK,
	BORAD_BLACK_QUEEN,
	BORAD_BLACK_KING,
	BORAD_WHITE_PAWN,
	BORAD_WHITE_KNIGHT,
	BORAD_WHITE_BISHOP,
	BORAD_WHITE_ROOK,
	BORAD_WHITE_QUEEN,
	BORAD_WHITE_KING,
	BORAD_LIGHT_BROWN,
	BORAD_BROWN,
	BORAD_BLANK,
	BORAD_MOVEABLE,
	BORAD_CATCH,
	RES_TYPE_BOARD_END
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
	void Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc, int x);
	BitMap* GetBitMap(string strFileName);
	void Release();
	ResManager();
	~ResManager();
};

