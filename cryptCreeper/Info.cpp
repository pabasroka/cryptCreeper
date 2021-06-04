#include "Info.h"

void Info::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->goBackText.setFont(this->font);

	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
}

void Info::initInfo()
{
	//Background
	this->background.setFillColor(sf::Color(3, 3, 28));
	this->background.setSize(sf::Vector2f(1900, 1600));

	//Buttons
	this->goBackButton.setFillColor(sf::Color::Blue);
	this->goBackButton.setOutlineColor(sf::Color::Green);
	this->goBackButton.setOutlineThickness(10.f);
	this->goBackButton.setSize(sf::Vector2f(400.f, 200.f));
	this->goBackButton.setPosition(sf::Vector2f(300, 1200));
}

void Info::buttonsClick(sf::RenderWindow& target, State& state)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& pos.x > this->goBackButton.getPosition().x
		&& pos.x < this->goBackButton.getPosition().x + this->goBackButton.getSize().x
		&& pos.y > this->goBackButton.getPosition().y
		&& pos.y < this->goBackButton.getPosition().y + this->goBackButton.getSize().y)
		state = State::mainMenu;
}

Info::Info()
{
	this->initVariables();
	this->initInfo();
}

Info::~Info()
{
}

void Info::update(sf::RenderWindow& target, State& state)
{
	this->buttonsClick(target, state);
}

void Info::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->goBackButton);
}
