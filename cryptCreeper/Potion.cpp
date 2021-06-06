#include "Potion.h"

void Potion::initVariables(int posX, int posY)
{
	bool condition = (rand() % 100) < 50;

	this->sprite.setTextureRect(sf::IntRect(2 * this->rectSize / 3,
		condition * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));
	this->sprite.setPosition(this->posX + 24, this->posY + 24);

	if (!condition)
		this->effect = 1;
	else
		this->effect = -1;
}

int Potion::getEffect()
{
	return this->effect;
}

Potion::Potion(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(this->posX, this->posY);
}

Potion::~Potion()
{
}
