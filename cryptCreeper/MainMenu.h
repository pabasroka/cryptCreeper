#pragma once
#include "utilities.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <fstream>

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

	//Highscore
	int highScore;
	sf::Text highScoreText;
	
	void initVariables();
	void initMainMenu();
	void initHighScore();
	void buttonsClick(sf::RenderWindow& target, State& state);
	void buttonsHover(sf::RenderWindow& target, sf::RectangleShape& button);

public:
	MainMenu();
	virtual ~MainMenu();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

