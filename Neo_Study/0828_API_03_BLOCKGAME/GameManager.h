#pragma once

class SingletonGameManager
{
private:
	static SingletonGameManager* sGameManager;

	SingletonGameManager() {

	}

public:
	static SingletonGameManager* getInstance() {
		
		if (sGameManager == nullptr)
		{
			sGameManager = new SingletonGameManager();
		}
		return sGameManager;

	}
	 
	void Init();

	void Update();

	void Relese()
	{
		delete sGameManager;
	}

};