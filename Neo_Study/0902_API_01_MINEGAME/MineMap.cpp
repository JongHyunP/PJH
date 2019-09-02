#include "MineMap.h"
#include "BitMap.h"


MineMap::MineMap()
{
}


MineMap::~MineMap()
{
}

void MineMap::Init(BitMap * pMap, BitMap * pResetBotton, int mapX, int mapY, int mapID, int resetX, int resetY, int resetID)
{
	m_pMap = pMap;
	m_pResetBotton = pResetBotton;

	m_MapX = mapX;
	m_MapY = mapY;
	m_MapID = mapID;
	m_ResetBottonX = resetX;
	m_ResetBottonY = resetY;
	m_ResetBottonID = resetID;
}

void MineMap::Draw(HDC hdc)
{
	m_pMap->Draw(hdc, m_MapX,m_MapY);
	m_pResetBotton->Draw(hdc, m_ResetBottonX, m_ResetBottonY);
}

bool MineMap::ResetButtonInput(POINT pt)
{
	return false;
}
