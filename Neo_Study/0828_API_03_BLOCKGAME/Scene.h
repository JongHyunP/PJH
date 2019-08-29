#pragma once
#include <Windows.h>

class Scene
{

public:
	Scene();
	~Scene();

	virtual void Create();

	virtual void Initialize() = 0;

	virtual void Update(float dt) = 0;

	virtual void Render(HDC hdc, float dt);

	virtual void Clear() = 0;

	virtual void Destroy() = 0;
};

