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
}

void Object::Draw(HDC hdc, bool bTrans)
{
	m_pBitMap->Draw(hdc, m_iX, m_iY, bTrans);
}

bool Object::Input(POINT pt)
{
	return false;
}
