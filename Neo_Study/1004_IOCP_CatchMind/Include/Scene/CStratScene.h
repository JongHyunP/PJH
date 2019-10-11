#pragma once
#include "CScene.h"
class CStratScene :
	public CScene
{
private:
	friend class SceneManager;

private:
	CStratScene();
	~CStratScene();

public:
	virtual bool Init();
};

