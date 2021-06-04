#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>

class Info
{
	//Info screen 
	sf::RectangleShape background;
	sf::RectangleShape goBackButton;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text goBackText;

	void initVariables();
	void initInfo();
	void buttonsClick(sf::RenderWindow& target, State& state);

public:
	Info();
	virtual ~Info();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

