#include "Player.h"
#include "BitMap.h"
#include "ResManager.h"


Player::Player()
{
	m_iFrame = 0;
	m_iFrameCount = 0;
	m_iX = 0;
	m_iY = 0;
	m_iCX = 0;
	m_iCY = 0;
	m_iSpeed = 0;
	m_ePlayerState = STOP;
}


Player::~Player()
{

}

void Player::Init(ResManager* pResManager , int x, int y, int cx, int cy)
{
	string storagePathPlayer[RES_TYPE_PLAYER_END] = { "RES\\player0.bmp","RES\\player1.bmp","RES\\player2.bmp","RES\\win.bmp","RES\\win2.bmp" ,"RES\\die.bmp" };

	for (int i = 0; i < RES_TYPE_PLAYER_END; i++)
	{
		m_vecBitMap.push_back(pResManager->GetBitMap(storagePathPlayer[i]));
	}
	m_iX = x;
	m_iY = y;
	m_iCX = cx;
	m_iCY = cy;
}

int Player::GetPosX()
{
	return m_iX;
}

void Player::Update()
{
	if (m_iX)
	{

	}
	m_iX = m_iX + m_iSpeed;

	m_iFrameCount++;
	
	if (m_iFrameCount == 10)
	{
		m_iFrameCount = 0;
		m_iFrame++;
		
		if (m_iFrame >= 3)
			m_iFrame = 0;
	}

	if (m_ePlayerState == STOP)
	{
		m_iSpeed = 0;
		m_iFrame = 0;
	}
	else if (m_ePlayerState == MOVE_FORWD)
	{
		m_iSpeed = 3;
	}
	else if (m_ePlayerState == MOVE_BACK)
	{
		m_iSpeed = -3;
	}

}

void Player::Move(int direction)
{
	if (direction == INPUT_STOP)
	{
		m_ePlayerState = STOP;
	}
	else if (direction == INPUT_RIGHT)
	{
		m_ePlayerState = MOVE_FORWD;
	}
	else if (direction == INPUT_LEFT)
	{
		m_ePlayerState = MOVE_BACK;
	}
}

void Player::Draw(HDC hdc)
{
	m_vecBitMap[m_iFrame]->Draw(hdc, m_iX, m_iY , true);
}