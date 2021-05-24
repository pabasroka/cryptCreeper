#pragma once
#include "Object.h"

class Sword : public Object
{
	void initVariables(int posX, int posY);
	int dmg;

public:
	Sword(int posX, int posY);
	virtual ~Sword();

	int getDmg();
};

