#include "Object.h"
#include "BitMap.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::Init(BitMap * pBitMap, int x, int y, int cx, int cy, int id)
{
	for (int i = 0; i < 4; i++)
	{
		m_pBitMap[i] = pBitMap;
	}
	m_iX = x;
	m_iY = y;
	m_iCX = cx;
	m_iCY = cy;
	m_iId = id;
	m_pRectObjectBox = nullptr;
	m_rectObject = { m_iX ,m_iY , m_iX + m_iCX, m_iY + m_iCY };
}

void Object::Draw(HDC hdc, bool bTrans)
{
	m_pBitMap[0]->Draw(hdc, m_iX, m_iY, 0, 0, m_iCX / 2, m_iCY / 2, bTrans);
	m_pBitMap[1]->Draw(hdc, m_iX, m_iY, m_iCX/2,0, m_iCX, m_iCY/2, bTrans);
	m_pBitMap[2]->Draw(hdc, m_iX, m_iY, 0, m_iCY/2, m_iCX/2, m_iCY, bTrans);
	m_pBitMap[3]->Draw(hdc, m_iX, m_iY, m_iCX / 2, m_iCY / 2,m_iCX, m_iCY, bTrans);
}

RECT Object::GetObjectRect()
{
	m_pRectObjectBox = &m_rectObject;

	return *m_pRectObjectBox;
}

bool Object::Input(POINT pt)
{
	return false;
}
