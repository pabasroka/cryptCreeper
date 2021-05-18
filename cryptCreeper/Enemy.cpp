#include "Enemy.h"

void Enemy::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(1 * this->rectSize,
		0 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->power = 1;
}

Enemy::Enemy(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Enemy::~Enemy()
{
	delete this;
}
