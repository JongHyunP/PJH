#pragma once
#include <Windows.h>

class Camera
{
	int			m_iCameraPosX; //ĳ���� ��ǥ���������

public:
	Camera();
	~Camera();
	void SetPosX(int playerX);
	int GetPosX();
};

