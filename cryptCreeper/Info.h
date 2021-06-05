#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <chrono>
#include <thread>

class Info
{
	//Info screen 
	sf::RectangleShape background;
	sf::RectangleShape goBackButton;
	sf::Texture mouseTexture;
	sf::Texture keysTexture;
	sf::Sprite mouse;
	sf::Sprite keys;
	sf::Font font;
	sf::Text goBackText;
	sf::Text controlsText;
	sf::Text mouseArrowsText;
	sf::Text rulesText;
	std::stringstream ss;

	void initVariables();
	void initInfo();
	void buttonsClick(sf::RenderWindow& target, State& state);
	void buttonsHover(sf::RenderWindow& target);

public:
	Info();
	virtual ~Info();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

