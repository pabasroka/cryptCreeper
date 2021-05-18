#include "Enemy.h"

void Enemy::initVariables(int posX, int posY)
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->text.setFont(this->font);

	this->sprite.setTextureRect(sf::IntRect(1 * this->rectSize,
		0 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->power = 1;

	//Field text
	this->text.setCharacterSize(120);
	this->text.setPosition(sf::Vector2f(this->posX + 0, this->posY + 2 * this->rectSize));
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(8.f);
	this->text.setString(std::to_string(this->power));
}

Enemy::Enemy(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Enemy::~Enemy()
{
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->text);
}
