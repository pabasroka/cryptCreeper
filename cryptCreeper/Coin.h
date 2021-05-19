#pragma once
#include "Object.h"

class Coin : public Object
{
	void initVariables(int posX, int posY);

public:
	Coin(int posX, int posY);
	virtual ~Coin();
	
};

