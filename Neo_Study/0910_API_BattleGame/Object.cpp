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
	m_pBitMap = pBitMap;
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
	m_pBitMap->Draw(hdc, m_iX, m_iY, bTrans);
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
