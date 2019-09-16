#include "Player.h"
#include "BitMap.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::Init(BitMap * pBitMap, float posX, float posY, int cx, int cy)
{
	m_pBitMap = pBitMap;
	m_fPlayerPosX = posX;
	m_fPlayerPosY = posY;
	m_iCX = cx;
	m_iCY = cy;
	m_rectPlayerBox = { m_fPlayerPosX ,m_fPlayerPosY ,m_iCX ,m_iCY };
}

void Player::Draw(HDC hdc, float posX, float posY)
{
	m_pBitMap->Draw(hdc, posX, posY, true);
}

RECT Player::GetPlayerRect()
{
	return m_rectPlayerBox;
}
