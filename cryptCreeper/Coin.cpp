#include "Coin.h"

void Coin::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		4 * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setPosition(this->posX + 24, this->posY + 12);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

}


Coin::Coin(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Coin::~Coin()
{
}

