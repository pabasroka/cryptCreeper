#pragma once
#include "Object.h"

class Coin : public Object
{
	void initVariables(int posX, int posY);
	int timerMax;
	int timer;
	int frame;
	bool reverse;

	void animation();

public:
	Coin(int posX, int posY);
	virtual ~Coin();
	
	void update();
};

