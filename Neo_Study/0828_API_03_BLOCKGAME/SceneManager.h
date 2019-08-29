#pragma once
#include <windows.h>
#include <string>
#include <map>
#include "Scene.h"
using namespace std;

class SceneManager : public Scene
{
private:

	map<string, Scene*>  sceneContainer;

	Scene*  reservedScene; // ¿¹¾à¾À
	Scene*  currentScene; // ÇöÀç¾À

public:
	SceneManager();
	~SceneManager();

	void registerScene(const string& sceneName, Scene* scene);
	void reserveChangeScene(const string& sceneName);

	void Update(int sceneUpdatenum);
	void Render(HDC hdc, float dt);
};

