#pragma once
#include "Object.h"
#include "Player.h"
class Player;

class Enemy : public Object
{
	int power; //dmg/hp
	int timerMax;
	int timer;
	int frame;

	sf::Font font;
	sf::Text text;

	void initVariables(int posX, int posY, int power);
	void animation();
	friend bool isPlayerIntersectSomething(Player& player, Object* object);

public:
	Enemy(int posX, int posY, int power);
	virtual ~Enemy();

	int getPower();

	void update();
	virtual void render(sf::RenderTarget& target);
};

