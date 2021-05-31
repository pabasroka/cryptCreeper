#include "Sword.h"

void Sword::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		1 * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setPosition(this->posX + 24, this->posY + 12);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

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