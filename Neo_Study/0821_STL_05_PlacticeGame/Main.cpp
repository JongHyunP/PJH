#include "Scene.h"

int main()
{
	Scene scene;

	while (!scene.systemEnd)
	{
		scene.ShowMenu();
	}

	return 0;
}