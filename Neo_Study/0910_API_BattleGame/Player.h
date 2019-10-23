#pragma once
#include <Windows.h>

/**
 * @file Player.h
 * @brief 플레이어 클래스 헤더.
 * @details .
 */

 /**
  * @brief 플레이어 클래스 헤더.
  * @details 플레이어에 대한 정보를 담고있습니다.
  * @author JongHyun Park, whdgus1590@naver.com
  * @date 2019-10
  * @version 0.0.1
  */

class BitMap;

enum PLAYER_STATE
{
	PLAYER_IDLE,
	PLAYER_MOVE,
	PLAYER_SHOOT,
	PLAYER_SHOOT_COOLTIME,
	PLAYER_DIE,
	PLAYER_STATE_END
};

class Player
{
	BitMap*			m_pBitMap;
	PLAYER_STATE	m_ePlayerState;
	float			m_fPlayerPosX;
	float			m_fPlayerPosY;
	int				m_iCX;
	int				m_iCY;
	int				m_iFrame;
	int				m_iFrameCount;
	bool			m_bIsCrush;
public:
	Player();
	~Player();
	void Init(BitMap* pBitMap, float posX, float posY, int cx, int cy);
	void Draw(HDC hdc, float posX, float posY);
	void Input();
	void Update();

};

