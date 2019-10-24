#pragma once
#include <Windows.h>
#include <chrono>
#include <vector>

/**
 * @file GameFrameWork.h
 * @brief ������ �ھ� ��� ����.
 */

 /**
  * @brief ������ �ھ� ���.
  * @details ���������� ���������� �մϴ�.
  * @author JongHyun Park, whdgus1590@naver.com
  * @date 2019-10
  * @version 0.0.1
  */

using namespace std;

#define FPS			60.0f
#define MAP_WIDTH 32
#define MAP_HIGHT 24

class Object;
class Player;

class GameFrameWork
{
private:
	HWND		m_hWnd;
	chrono::system_clock::time_point m_LastTime;
	float		m_fElapseTime;
	Player*		m_pPlayer;
	Object*     m_pObject[32][24];
	vector<Object*>	m_vecFixedObject;
	float		Player_x; 
	float		Player_y; 
	float		m_fFrameCount;
	float		m_fFrame;
public:
	GameFrameWork();
	~GameFrameWork();

	bool Init(HWND hWnd, HDC hdc);
	void Release();
	void Update(HDC hdc);
	void OperateInput();
	void MapObjectSetting();
	void CollisionCheck();
	void Animaition();
	void Render(HDC hdc);

};

