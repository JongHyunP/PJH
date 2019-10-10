#pragma once
#include "value.h"

enum RES_TYPE
{
	RES_TYPE_00,
	RES_TYPE_01,
	RES_TYPE_02,
	RES_TYPE_03,
	RES_TYPE_04,
	RES_TYPE_05,
	RES_TYPE_06,
	RES_TYPE_07,
	RES_TYPE_08,
	RES_TYPE_09,
	RES_TYPE_BACK,
	RES_TYPE_END
};

class CBitMap;

class CResManager
{
	DECLARE_SINGLE(CResManager)

private:
	map<string, CBitMap*>	m_mapBitMap;
	HDC						m_hMemDC;
	HBITMAP					m_hBitMap;
	HBITMAP					m_hOldBitMap;

public:
	bool Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc);
	CBitMap* GetBitMap(string strFileName);
	void Release();
};

