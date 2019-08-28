#pragma once

class Singleton 
{
private:
	static Singleton* singleton;

	Singleton() {

	}

public:
	static Singleton getInstance() {
		
		if (singleton == nullptr)
		{
			singleton = new Singleton();
		}
		return *singleton;

	}

	void Relese()
	{
		delete singleton;
	}

};