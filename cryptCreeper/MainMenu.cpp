#include "MainMenu.h"

void MainMenu::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->text.setFont(this->font);

	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
}

void MainMenu::initMainMenu()
{
	//Background
	this->background.setFillColor(sf::Color(3, 3, 28));
	this->background.setSize(sf::Vector2f(1900, 1600));

	//Buttons
	this->startGameButton.setFillColor(sf::Color::Blue);
	this->startGameButton.setOutlineColor(sf::Color::Green);
	this->startGameButton.setOutlineThickness(10.f);
	this->startGameButton.setSize(sf::Vector2f(400.f, 200.f));
	this->startGameButton.setPosition(sf::Vector2f(300, 50));

	this->infoButton = this->startGameButton;
	this->infoButton.setPosition(sf::Vector2f(300, 550));

	this->exitButton = this->startGameButton;
	this->exitButton.setPosition(sf::Vector2f(300, 1050));
}

void MainMenu::buttonsClick(sf::RenderWindow& target, State& state)
{
	//Start game
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		state = State::area;

	//Game info

	//Exit 
}

MainMenu::MainMenu()
{
	this->initVariables();
	this->initMainMenu();
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::RenderWindow& target, State& state)
{
	this->buttonsClick(target, state);
}

void MainMenu::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->startGameButton);
	target.draw(this->infoButton);
	target.draw(this->exitButton);
	target.draw(this->text);
}
