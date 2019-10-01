#pragma once

enum PLAYER_STATE
{
	PLAYER_WAIT,
	PLAYER_TURN
};

class Player
{
private:
	int m_iPoint; //Á¡¼ö
	PLAYER_STATE m_ePlayerState;

public:
	Player();
	~Player();
};

