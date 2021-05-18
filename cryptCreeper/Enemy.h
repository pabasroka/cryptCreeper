#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
class Player;
class Enemy
{
	int power; //dmg/hp
	

	//Position
	int posX;
	int posY;

	//Sprites
	int rectSize;
	sf::Texture texture;
	sf::Sprite enemySprite;

	void initVariables(int posX, int posY);
	friend bool isPlayerIntersectSomething(Player& player, Enemy* enemy);

public:
	Enemy(int posX, int posY);
	virtual ~Enemy();
	bool isAlive;
	sf::Vector2f getPosition();

	void render(sf::RenderTarget& target);
};

