#include "Camera.h"



Camera::Camera()
{
	m_iCameraPosX = 0;
}


Camera::~Camera()
{
}

void Camera::SetPosX(int playerX)
{
	m_iCameraPosX = playerX;
}

int Camera::GetPosX()
{
	return m_iCameraPosX;
}


