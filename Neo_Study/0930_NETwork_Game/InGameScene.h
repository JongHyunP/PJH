#pragma once
#include "Scene.h"
class InGameScene :
	public Scene
{
private:
	friend class SceneManager; //���Ŵ������� �����̺����ٰ���

private:
	InGameScene();
	virtual ~InGameScene();

public:
	virtual bool Init();
};

