#pragma once
#include "Object.h"
#include "Enemy.h"
class Enemy;

class Player : public Object
{
	//Stats
	int hp;
	int sword;
	int shield;
	int coin;
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

	// Getters / setters
	int getHp();
	int getSword();
	int getShield();
	int getCoin();
	int getScore();
	void setHp(int hp);
	void setSword(int sword);
	void setShield(int shield);
	void setScore(int score);
	void setCoin(int coin);
	bool isDead();

	void update();
};

