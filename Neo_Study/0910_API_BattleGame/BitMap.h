#pragma once
#include <Windows.h>
#include <string>
using namespace std;

/**
 * @file BitMap.h
 * @brief ��Ʈ�� ���.
 * @details ��Ʈ�� �̹��� ����� ���� ���.
 */

 /**
  * @brief ��Ʈ�� �̹��� Ŭ����.
  * @details ������ ��Ʈ�� �̹��� ��� ������ ��.
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

