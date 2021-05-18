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
	static int counter;

	sf::RectangleShape field;
	int xPos;
	int yPos;
	int size;
	sf::Font font;
	sf::Text text;

	void initVariables(int xPos, int yPos, int size = 50);
	void initField();

public:
	Field(int xPos, int yPos, int size = 50);
	virtual ~Field();

	void mouseClick(sf::RenderWindow& target);

	static int getCounter();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};
