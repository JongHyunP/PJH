#include "Object.h"
#include "BitMap.h"

void Object::Init(BitMap* pObject, int posX, int posY)
{
	m_pObject = pObject;
	m_ObjectPosX = posX;
	m_ObjectPosY = posY;
}

void Object::Draw(HDC hdc)
{
	m_pObject->Draw(hdc, m_ObjectPosX, m_ObjectPosY);
}
