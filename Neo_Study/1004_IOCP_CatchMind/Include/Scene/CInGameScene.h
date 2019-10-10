#pragma once
#include "CScene.h"
class CInGameScene :
	public CScene
{
private:
	friend class SceneManager;
private:
	CInGameScene();
	virtual ~CInGameScene();

public:
	virtual bool Init();
};

