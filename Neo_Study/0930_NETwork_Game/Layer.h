#pragma once
#include "value.h"

class Layer
{
private:
	friend class Scene;
private:
	Layer();
	~Layer();
private:
	string m_strTag;
	int m_iZOrder;
};

