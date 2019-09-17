#include "EditorObject.h"
#include "BitMap.h"


void EditorObject::Init(BitMap * pBitMap, int x, int y, int cx, int cy, int id)
{
	m_pBitMap = pBitMap;
	m_iX = x;
	m_iY = y;
	m_iCX = cx;
	m_iCY = cy;
	m_iId = id;
}

void EditorObject::Draw(HDC hdc, bool bTrans)
{
	m_pBitMap->Draw(hdc, m_iX , m_iY, bTrans);
}

bool EditorObject::Input(POINT pt)
{
	RECT rc = { m_iX  , m_iY , m_iX + 25  , m_iY + 25 };

	if (PtInRect(&rc, pt))
	{

		return true;
	}
	return false;
}

EditorObject::EditorObject()
{
}


EditorObject::~EditorObject()
{
}
