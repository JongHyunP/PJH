#pragma once
#include "resource.h"
#include "BitMap.h"

enum BITMAP_TYPE {
	BITMAP_01,
	BITMAP_02,
	BITMAP_03,
	BITMAP_04,
	BITMAP_05,
	BITMAP_06,
	BITMAP_07,
	BITMAP_08,
	BITMAP_09,
	BITMAP_10,
	BITMAP_END
};

class ResourceManager
{
	
public:
	ResourceManager();
	~ResourceManager();

	void Init();
};

