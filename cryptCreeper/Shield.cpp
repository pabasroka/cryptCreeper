#include "Shield.h"

void Shield::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		2 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->armor = 1;
}

Shield::Shield(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Shield::~Shield()
{
}

int Shield::getArmor()
{
	return this->armor;
}
