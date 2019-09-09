#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

enum INPUT_KEY_DIRECTION
{
	INPUT_STOP,
	INPUT_LEFT,
	INPUT_RIGHT,
	INPUT_JUMP,
	INPUT_END
};

enum PLAYER_STATE
{
	STOP,
	MOVE_FORWD,
	MOVE_BACK,
	JUMP
};

class BitMap;

class ResManager;

class Player
{
private:
	vector<BitMap*>	m_vecBitMap;
	int				m_iFrame;
	int				m_iFrameCount;
	int				m_iX;
	int				m_iY;
	int				m_iCX;
	int				m_iCY;
	int				m_iSpeed;
	PLAYER_STATE	m_ePlayerState;
public:
	void Init(ResManager* pResManager , int x , int y , int cx , int cy);
	void Update();
	void Move(int direction);
	void Draw(HDC hdc);
	Player();
	~Player();
};

