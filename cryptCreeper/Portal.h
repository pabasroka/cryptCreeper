#pragma once
#include "Object.h"

class Portal : public Object
{
	int timerMax;
	int timer;
	int frame;

	void initVariables(int posX, int posY);

public:
	Portal(int posX, int posY);
	virtual ~Portal();

	void animation();
};

