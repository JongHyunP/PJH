#pragma once
#include <Windows.h>
#include <map>
#include <string>
using namespace std;

#define WIN_X 800
#define WIN_Y 600
#define MAX_SIZE 800

class BitMap;
class ResManager
{
private:
	map<string, BitMap*>	m_mapBitMap;
	HDC						m_hMemDC;
	HBITMAP					m_hBitMap;
	HBITMAP					m_hOldBitMap;
public:
	int						m_iDisplayX;
	void Init(HDC hdc);
	void InitBackBuffer(HDC hdc);
	HDC GetBackBuffer();
	void DrawScene(HDC hdc);
	BitMap* GetBitMap(string strFileName);
	void Release();
	ResManager();
	~ResManager();
};

