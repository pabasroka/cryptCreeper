#include "Sword.h"

void Sword::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		1 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->dmg = 1;
}

Sword::Sword(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Sword::~Sword()
{
}

int Sword::getDmg()
{
	return this->dmg;
}