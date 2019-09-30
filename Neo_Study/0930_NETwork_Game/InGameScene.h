#pragma once
#include "Scene.h"
class InGameScene :
	public Scene
{
private:
	friend class SceneManager; //씬매니저에서 프라이빗접근가능

private:
	InGameScene();
	virtual ~InGameScene();

public:
	virtual bool Init();
};

