#include "Shield.h"

void Shield::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		2 * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setPosition(this->posX + 24, this->posY + 12);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

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
