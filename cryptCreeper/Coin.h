#pragma once
#include "Object.h"

class Coin : public Object
{

public:
	Coin(int posX, int posY);
	virtual ~Coin();
	void initVariables(int posX, int posY);
};

