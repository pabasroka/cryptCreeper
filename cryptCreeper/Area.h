#pragma once
#include "Field.h"
#include "HUD.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"
#include "Portal.h"

class Area
{
	std::vector<Field*> fields;
	std::vector<Enemy*> enemies;
	std::vector<Coin*> coins;
	HUD hud;
	Player player;
	Portal* portal;

	//dev tools
	int timerMax;
	int timer;

	void initFirstArea();
	void initNewArea();
	void randomizer(int posX, int posY);

public:
	Area();
	virtual ~Area();

	bool endGame();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

