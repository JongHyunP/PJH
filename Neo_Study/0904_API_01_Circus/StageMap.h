#pragma once
#include <Windows.h>

using namespace std;

class BitMap;

class StageMap
{
private:
	//BitMap*					m_pGrassField;
	//BitMap*					m_pElephant;
	//BitMap*					m_pCrowdOne;
	//BitMap*					m_pCrowdTwo;


public:
	StageMap();
	~StageMap();

	virtual void Init();
	virtual void Draw(HDC hdc);
};

