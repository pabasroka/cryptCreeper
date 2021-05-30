#include "Portal.h"

void Portal::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		5 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

}

Portal::Portal(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Portal::~Portal()
{
}