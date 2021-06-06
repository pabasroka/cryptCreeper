#pragma once
#include "Object.h"

class Potion : public Object
{
	int effect; // 1 - heal potion, -1 - poison potion

	void initVariables(int posX, int posY);

public:

	int getEffect();

	Potion(int posX, int posY);
	virtual ~Potion();
};

