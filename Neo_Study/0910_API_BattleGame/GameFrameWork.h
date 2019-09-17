#pragma once
#include <Windows.h>
#include <chrono>
#include <vector>

using namespace std;

#define FPS			60.0f
#define MAP_WIDTH 32
#define MAP_HIGHT 24

enum STATE
{
	IDLE,
	MOVE,
	JUMP
};

class ResManager;
class Object;
class Player;

class GameFrameWork
{
private:
	HWND		m_hWnd;
	chrono::system_clock::time_point m_LastTime;
	float		m_fElapseTime;

	ResManager*	m_pResManager;
	Player*		m_pPlayer;
	Object*     m_pObject[32][24];
	vector<Object*>	m_vecFixedObject;
	float		Player_x; // 플레이어 클래스에서 값 받아오기.
	float		Player_y; 

	bool		m_bIsCrush;
	bool		m_bJump;
	//수학적으로
	STATE		m_eState;
	float		m_fJumpX;
	float		m_fJumpY;
	float		m_fCurJumpTime;

	//물리적
	float		m_fVectorX;
	float		m_fVectorY;

	//애니메이션용
	float		m_fFrameCount;
	float		m_fFrame;
public:
	GameFrameWork();
	~GameFrameWork();

	void Init(HWND hWnd, HDC hdc);
	void Release();
	void Update(HDC hdc);
	void OperateInput();
	void CollisionCheck();
	void Animaition();
	void Render(HDC hdc);

};

