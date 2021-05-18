#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"
class Enemy;
class Player
{
	//Stats
	int hp;
	int dmg;
	int money;
	int score;

	//Position
	int posX;
	int posY;

	//Sprites
	int rectSize;
	sf::Texture texture;
	sf::Sprite playerSprite;

	//Others
	int movementTimer;
	int movementTimerMax;

	void initVariables();
	void move();
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Player();
	virtual ~Player();

	sf::Vector2f getPosition();

	void update();
	void render(sf::RenderTarget& target);
};

