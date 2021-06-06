#pragma once
#include "Object.h"

class Vendor : public Object
{	
	void initVariables(int posX, int posY);

public:
	Vendor(int posX, int posY);
	virtual ~Vendor();
};

