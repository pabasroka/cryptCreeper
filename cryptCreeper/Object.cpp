#include "Object.h"

void Object::initVariables(int posX, int posY)
{
	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
	this->rectSize = 48;
	this->posX = posX;
	this->posY = posY;

	this->sprite.setPosition(this->posX, this->posY);
}

Object::Object(int posX, int posY)
{
	this->initVariables(posX, posY);
}

Object::~Object()
{
}

sf::Vector2f Object::getPosition()
{
	return sf::Vector2f(this->posX, this->posY);
}

void Object::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
