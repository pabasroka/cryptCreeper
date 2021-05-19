#pragma once
#include "Object.h"
#include "Player.h"
class Player;

class Enemy : public Object
{
	int power; //dmg/hp

	sf::Font font;
	sf::Text text;

	void initVariables(int posX, int posY, int power);
	friend bool isPlayerIntersectSomething(Player& player, Object* object);

public:
	Enemy(int posX, int posY, int power);
	virtual ~Enemy();
	virtual void render(sf::RenderTarget& target);
};

