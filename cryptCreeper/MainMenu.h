#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>

class MainMenu
{
	// Main menu screen
	sf::RectangleShape background;
	sf::RectangleShape startGameButton;
	sf::RectangleShape infoButton;
	sf::RectangleShape exitButton;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text text;

	void initVariables();
	void initMainMenu();
	void buttonsClick(sf::RenderWindow& target, State& state);

public:
	MainMenu();
	virtual ~MainMenu();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

