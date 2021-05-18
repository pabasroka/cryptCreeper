#pragma once
#include "Field.h"
#include "HUD.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"

class Area
{
	std::vector<Field*> fields;
	std::vector<Enemy*> enemies;
	std::vector<Coin*> coins;
	HUD hud;
	Player player;

	//dev tools
	int timerMax;
	int timer;

	void initNewArea();
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Area();
	virtual ~Area();

	bool endGame();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

