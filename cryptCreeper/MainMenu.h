#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

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
	sf::Text titleText;
	sf::Text startGameText;
	sf::Text infoText;
	sf::Text exitText;

	void initVariables();
	void initMainMenu();
	void buttonsClick(sf::RenderWindow& target, State& state);
	void buttonsHover(sf::RenderWindow& target);

public:
	MainMenu();
	virtual ~MainMenu();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

