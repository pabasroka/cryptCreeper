#include "HUD.h"

void HUD::initVariable()
{
	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sword.setTexture(this->texture);
	this->shield.setTexture(this->texture);
	this->heart.setTexture(this->texture);
	this->rectSize = 48;
}

void HUD::initHUD()
{
	this->background.setSize(sf::Vector2f(1000.f, 300.f));
	this->background.setFillColor(sf::Color::Red);
	this->background.setPosition(sf::Vector2f(0.f, 1000.f));

	this->sword.setTextureRect(sf::IntRect(0 * this->rectSize, 1 * this->rectSize,
		this->rectSize, this->rectSize));
	this->shield.setTextureRect(sf::IntRect(0 * this->rectSize, 2 * this->rectSize,
		this->rectSize, this->rectSize));
	this->heart.setTextureRect(sf::IntRect(0 * this->rectSize, 3 * this->rectSize,
		this->rectSize, this->rectSize));

	this->sword.setScale(sf::Vector2f(3.f, 3.f));
	this->shield.setScale(sf::Vector2f(3.f, 3.f));
	this->heart.setScale(sf::Vector2f(3.f, 3.f));

	this->sword.setPosition(sf::Vector2f(50.f, 1050.f));
	this->shield.setPosition(sf::Vector2f(250.f, 1050.f));
	this->heart.setPosition(sf::Vector2f(550.f, 1050.f));
}

HUD::HUD()
{
	this->initVariable();
	this->initHUD();
}

HUD::~HUD()
{
}

void HUD::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->sword);
	target.draw(this->shield);
	target.draw(this->heart);
}
