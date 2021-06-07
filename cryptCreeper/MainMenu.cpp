#include "MainMenu.h"

void MainMenu::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->startGameText.setFont(this->font);
	this->infoText = this->startGameText;
	this->exitText = this->startGameText;

	if (!this->texture.loadFromFile("Sprites/mainMenuSprite.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
}

void MainMenu::initMainMenu()
{
	//Background
	this->background.setFillColor(sf::Color(3, 3, 28));
	this->background.setSize(sf::Vector2f(1900, 1600));

	//Sprite
	this->sprite.setPosition(sf::Vector2f(650, 75));
	this->sprite.setScale(sf::Vector2f(8.f, 8.f));

	//Buttons
	this->startGameButton.setFillColor(sf::Color::Blue);
	this->startGameButton.setOutlineColor(sf::Color(251, 133, 0));
	this->startGameButton.setOutlineThickness(10.f);
	this->startGameButton.setSize(sf::Vector2f(400.f, 200.f));
	this->startGameButton.setPosition(sf::Vector2f(300, 400));

	this->infoButton = this->startGameButton;
	this->infoButton.setPosition(sf::Vector2f(300, 800));

	this->exitButton = this->startGameButton;
	this->exitButton.setPosition(sf::Vector2f(300.f, 1200.f));

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
	this->infoText.setPosition(sf::Vector2f(this->infoButton.getPosition().x + 100,
		this->infoButton.getPosition().y + 30));

	this->exitText = this->startGameText;
	this->exitText.setString("Exit");
	this->exitText.setPosition(sf::Vector2f(this->exitButton.getPosition().x + 100,
		this->exitButton.getPosition().y + 30));

	this->titleText = this->startGameText;
	this->titleText.setCharacterSize(120);
	this->titleText.setPosition(sf::Vector2f(200, 0));
	this->titleText.setString("Crypt Creeper");
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
	{
		state = State::area;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

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

void MainMenu::buttonsHover(sf::RenderWindow& target, sf::RectangleShape& button)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	if (pos.x > button.getPosition().x
		&& pos.x < button.getPosition().x + button.getSize().x
		&& pos.y > button.getPosition().y
		&& pos.y < button.getPosition().y + button.getSize().y)
	{
		button.setFillColor(sf::Color::Red);
		button.setOutlineColor(sf::Color(251, 233, 120));
	}
	else
	{
		button.setFillColor(sf::Color::Blue);
		button.setOutlineColor(sf::Color(251, 133, 0));
	}

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
	this->buttonsHover(target, this->startGameButton);
	this->buttonsHover(target, this->infoButton);
	this->buttonsHover(target, this->exitButton);
	this->buttonsClick(target, state);
}

void MainMenu::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->sprite);
	target.draw(this->startGameButton);
	target.draw(this->infoButton);
	target.draw(this->exitButton);
	target.draw(this->titleText);
	target.draw(this->startGameText);
	target.draw(this->infoText);
	target.draw(this->exitText);
}
