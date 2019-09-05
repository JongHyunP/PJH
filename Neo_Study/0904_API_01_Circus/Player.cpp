#include "Player.h"
#include "BitMap.h"

void Player::Init(BitMap* pPlayer, int posX, int posY)
{
	m_pPlayer = pPlayer;
	m_PlayerPosX = posX;
	m_PlayerPosY = posY;
}

void Player::Draw(HDC hdc)
{
	m_pPlayer->Draw(hdc, m_PlayerPosX, m_PlayerPosY,0,0);
}
