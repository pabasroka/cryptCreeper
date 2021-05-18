#include "Coin.h"

void Coin::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		4 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));
}


Coin::Coin(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Coin::~Coin()
{
}

