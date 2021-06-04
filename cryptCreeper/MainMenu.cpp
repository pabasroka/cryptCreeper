#include "MainMenu.h"

void MainMenu::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->startGameText.setFont(this->font);
	this->infoText = this->startGameText;
	this->exitText = this->startGameText;

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

	//Text
	this->startGameText.setCharacterSize(100);
	this->startGameText.setPosition(sf::Vector2f(this->startGameButton.getPosition().x + 40,
		this->startGameButton.getPosition().y + 30));
	this->startGameText.setFillColor(sf::Color::White);
	this->startGameText.setOutlineColor(sf::Color::Black);
	this->startGameText.setOutlineThickness(10.f);
	this->startGameText.setString("New game");

	this->infoText = this->startGameText;
	this->infoText.setString("Info");
	this->infoText.setPosition(sf::Vector2f(this->infoButton.getPosition().x + 40,
		this->infoButton.getPosition().y + 30));

	this->exitText = this->startGameText;
	this->exitText.setString("Exit");
	this->exitText.setPosition(sf::Vector2f(this->exitButton.getPosition().x + 40,
		this->exitButton.getPosition().y + 30));
}

void MainMenu::buttonsClick(sf::RenderWindow& target, State& state)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	//Start game
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& pos.x > this->startGameButton.getPosition().x
		&& pos.x < this->startGameButton.getPosition().x + this->startGameButton.getSize().x
		&& pos.y > this->startGameButton.getPosition().y
		&& pos.y < this->startGameButton.getPosition().y + this->startGameButton.getSize().y)
		state = State::area;

	//Game info
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& pos.x > this->infoButton.getPosition().x
		&& pos.x < this->infoButton.getPosition().x + this->infoButton.getSize().x
		&& pos.y > this->infoButton.getPosition().y
		&& pos.y < this->infoButton.getPosition().y + this->infoButton.getSize().y)
		state = State::info;

	//Exit 
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& pos.x > this->exitButton.getPosition().x
		&& pos.x < this->exitButton.getPosition().x + this->exitButton.getSize().x
		&& pos.y > this->exitButton.getPosition().y
		&& pos.y < this->exitButton.getPosition().y + this->exitButton.getSize().y)
		state = State::exit;
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
	target.draw(this->startGameText);
	target.draw(this->infoText);
	target.draw(this->exitText);
}
