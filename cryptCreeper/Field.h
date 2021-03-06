#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>

class Field
{
	//Sprites
	int rectSize;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::RectangleShape field;
	int xPos;
	int yPos;
	int size;
	sf::Font font;
	sf::Text text;

	void initVariables(int xPos, int yPos);
	void initField(int lvl);

public:
	Field(int xPos, int yPos, int size = 50, int lvl = 1);
	virtual ~Field();

	void render(sf::RenderTarget& target);
};
