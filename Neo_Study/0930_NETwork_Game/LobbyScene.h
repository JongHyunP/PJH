#pragma once
#include "Scene.h"
class LobbyScene :
	public Scene
{
private:
	friend class SceneManager;

private:
	LobbyScene();
	virtual ~LobbyScene();
public:
	virtual bool Init();
};

