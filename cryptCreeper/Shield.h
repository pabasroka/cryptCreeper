#pragma once
#include "Object.h"

class Shield : public Object
{
	void initVariables(int posX, int posY);
	int armor;

public:
	Shield(int posX, int posY);
	virtual ~Shield();

	int getArmor();
};

