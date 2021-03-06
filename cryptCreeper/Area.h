#pragma once
#include "utilities.h"
#include "Field.h"
#include "HUD.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"
#include "Portal.h"
#include "Sword.h"
#include "Shield.h"
#include "Potion.h"
#include "Vendor.h"
#include "Trophy.h"

class Area
{
	std::vector<Field*> fields;
	std::vector<Enemy*> enemies;
	std::vector<Coin*> coins;
	std::vector<Sword*> swords;
	std::vector<Shield*> shields;
	std::vector<Potion*> potions;
	HUD hud;
	Player* player;
	Portal* portal;
	Trophy* trophy;
	Vendor* vendor;
	bool isVendorSpawn;
	bool isVendorClosed;

	//dev tools
	int timerMax;
	int timer;

	void initFirstArea();
	void initNewArea();
	void randomizer(int posX, int posY);

public:
	Area();
	virtual ~Area();

	void updateHud();
	bool endGame();
	Player& getPlayer();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

