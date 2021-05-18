#pragma once
#include "Object.h"
#include "Player.h"
class Player;

class Enemy : public Object
{
	int power; //dmg/hp

	void initVariables(int posX, int posY);
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Enemy(int posX, int posY);
	virtual ~Enemy();
};

