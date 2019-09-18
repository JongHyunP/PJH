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
	m_iFrame = 0;
	m_iFrameCount = 0;
	m_ePlayerState = PLAYER_IDLE;
	m_pBitMap = pBitMap;
	m_fPlayerPosX = posX;
	m_fPlayerPosY = posY;
	m_iCX = cx;
	m_iCY = cy;
	m_bIsCrush = false;
}

void Player::Draw(HDC hdc, float posX, float posY)
{
	m_pBitMap->Draw(hdc, posX, posY,0,0,m_iCX,m_iCY, true);
}

void Player::Update()
{
	//m_iX = m_iX + m_iSpeed;

	m_iFrameCount++;

	if (m_iFrameCount == 10)
	{
		m_iFrameCount = 0;
		m_iFrame++;

		if (m_iFrame >= 3)
			m_iFrame = 0;
	}

}

