#include "Enemy.h"

void Enemy::initVariables(int posX, int posY)
{
	this->rectSize = 48;
	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->enemySprite.setTexture(this->texture);
	this->enemySprite.setTextureRect(sf::IntRect(1 * this->rectSize,
		0 * this->rectSize, this->rectSize, this->rectSize));
	this->enemySprite.setScale(sf::Vector2f(4.f, 4.f));

	this->power = 1;
	this->isAlive = true;
	this->posX = posX;
	this->posY = posY;

	this->enemySprite.setPosition(this->posX, this->posY);
}

Enemy::Enemy(int posX, int posY)
{
	this->initVariables(posX, posY);
}

Enemy::~Enemy()
{
	delete this;
}

sf::Vector2f Enemy::getPosition()
{
	return sf::Vector2f(this->posX, this->posY);
}

void Enemy::render(sf::RenderTarget& target)
{
	if (isAlive)
		target.draw(this->enemySprite);
}
