#pragma once
#include <Windows.h>

class Camera
{
	int			m_iCameraPosX; //캐릭터 좌표맞춘다음에

public:
	Camera();
	~Camera();
	void SetPosX(int playerX);
	int GetPosX();
};

