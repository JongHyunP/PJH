#pragma once
#include <Windows.h>
#include <string>
using namespace std;

/**
 * @file BitMap.h
 * @brief 비트맵 헤더.
 * @details 비트맵 이미지 출력을 위한 헤더.
 */

 /**
  * @brief 비트맵 이미지 클래스.
  * @details 게임의 비트맵 이미지 출력 역할을 함.
  * @author JongHyun Park, whdgus1590@naver.com
  * @date 2019-10
  * @version 0.0.1
  */

class BitMap
{
private:
	HDC m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;

public:
	void Init(HDC hdc, string strFileName);
	void Draw(HDC hdc, int x, int y, int cx1 , int cy1 , int cx2, int cy2, bool bTrans);
	void Release();


	BitMap();
	~BitMap();
};

