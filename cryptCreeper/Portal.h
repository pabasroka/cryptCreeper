#pragma once
#include "Object.h"

class Portal : public Object
{
	void initVariables(int posX, int posY);

public:
	Portal(int posX, int posY);
	virtual ~Portal();
};

