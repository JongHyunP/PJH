#pragma once
#include <Windows.h>

/**
 * @file Object.h
 * @brief ������Ʈ Ŭ���� ���.
 * @details .
 */

 /**
  * @brief ������Ʈ Ŭ���� ���.
  * @details ȭ�鿡 �������� �� ���������� �մϴ�.
  * @author JongHyun Park, whdgus1590@naver.com
  * @date 2019-10
  * @version 0.0.1
  */

class BitMap;

class Object
{
	BitMap* m_pBitMap[4];
	int m_iX;
	int m_iY;
	int m_iCX;
	int m_iCY;
	int m_iId;

	RECT m_rectObject;
	RECT* m_pRectObjectBox;
public:
	Object();
	~Object();
	void Init(BitMap* pBitMap, int x, int y, int cx, int cy,int id);
	void Draw(HDC hdc, bool bTrans);
	RECT GetObjectRect();
	bool Input(POINT pt);

	int GetObjectID() 
	{
		return m_iId;
	}
	int GetObjectX()
	{
		return m_iX;
	}
	int GetObjectY()
	{
		return m_iY;
	}
};

