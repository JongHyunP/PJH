#pragma once
#include <Windows.h>

enum RES_TYPE
{
	RES_TYPE_BACKGROUND,
	RES_TYPE_BLOCK,
	RES_TYPE_NONE,
	RES_TYPE_01,
	RES_TYPE_02,
	RES_TYPE_03,
	RES_TYPE_04,
	RES_TYPE_05,
	RES_TYPE_06,
	RES_TYPE_07,
	RES_TYPE_08,
	RES_TYPE_FLAG,
	RES_TYPE_MINE,
	RES_TYPE_END
};

class BitMap;

class ResManager
{
private:
	BitMap* m_pBitMap[RES_TYPE_END];
public:
	void Init(HDC hdc, HINSTANCE hInst);
	BitMap* GetBitMap(int index);
	void Release();
	ResManager();
	~ResManager();
};

