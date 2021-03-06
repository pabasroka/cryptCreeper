#pragma once
#include "Object.h"
#include "Enemy.h"
class Enemy;

class Player : public Object
{
	//Stats
	int lvl; //hidden value (MAX lvl - 10)
	int hp;
	int sword;
	int shield;
	int coin;
	int score;

	//Others
	int movementTimer;
	int movementTimerMax;
	
	void initVariables(int posX, int posY);
	void move(sf::RenderWindow& target);
	void moveKeyboard();
	void moveMouse(sf::RenderWindow& target);
	bool isAnyLegitMove();
	friend bool isPlayerIntersectSomething(Player* player, Object* object);

public:
	Player(int posX, int posY);
	virtual ~Player();

	//Movement
	sf::Vector2i currentPos;
	bool movementArea[5][5]{};

	void showMovementArea();
	void clearMovementArea();

	// Getters / setters
	int getLvl();
	int getHp();
	int getSword();
	int getShield();
	int getCoin();
	int getScore();
	void setLvl(int lvl);
	void setHp(int hp);
	void setSword(int sword);
	void setShield(int shield);
	void setScore(int score);
	void setCoin(int coin);
	void setPosition(int posX, int posY);
	void addHp(int hp);
	void addSword(int sword);
	void addShield(int shield);
	void addHeart(int heart);
	void takeDamage(int damage);
	bool isDead();

	void nextAreaSettings();

	void update(sf::RenderWindow& target);
};

