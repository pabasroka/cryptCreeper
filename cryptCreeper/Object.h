#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Object
{
protected:

	//Position
	int posX;
	int posY;

	//Sprites
	int rectSize;
	sf::Texture texture;
	sf::Sprite sprite;

	virtual void initVariables(int posX, int posY);

public:
	Object(int posX, int posY);
	virtual ~Object();

	virtual sf::Vector2f getPosition();
	virtual void render(sf::RenderTarget& target);
};

