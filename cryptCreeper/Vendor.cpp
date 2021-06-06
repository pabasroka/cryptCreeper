#include "Vendor.h"

void Vendor::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(2 * this->rectSize / 3,
		2 * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));
	this->sprite.setPosition(this->posX + 12, this->posY + 12);
}

Vendor::Vendor(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Vendor::~Vendor()
{
}
