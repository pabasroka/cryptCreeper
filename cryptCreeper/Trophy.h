#pragma once
#include "Object.h"
class Trophy : public Object
{
	int timerMax;
	int timer;
	int frame;

	void initVariables(int posX, int posY);
	void animation();

public:
	Trophy(int posX, int posY);
	virtual ~Trophy();

	void update();
};

