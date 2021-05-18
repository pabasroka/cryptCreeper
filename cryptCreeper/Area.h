#pragma once
#include "Field.h"
#include "HUD.h"
#include "Player.h"
#include "Enemy.h"

class Area
{
	std::vector<Field*> fields;
	std::vector<Enemy*> enemies;
	HUD hud;
	Player player;

	void initNewArea();
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Area();
	virtual ~Area();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

