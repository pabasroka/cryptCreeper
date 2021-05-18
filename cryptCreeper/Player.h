#pragma once
#include "Object.h"
#include "Enemy.h"
class Enemy;

class Player : public Object
{
	//Stats
	int hp;
	int dmg;
	int money;
	int score;


	//Others
	int movementTimer;
	int movementTimerMax;

	void initVariables(int posX, int posY);
	void move();
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Player();
	virtual ~Player();

	void addScore(int score);

	void update();
};

