#include "Trophy.h"

void Trophy::initVariables(int posX, int posY)
{
	if (!this->texture.loadFromFile("Sprites/trophy.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->posX, this->posY - 200);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

	this->frame = 0;
	this->timerMax = 15;
	this->timer = this->timerMax;
}

Trophy::Trophy(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Trophy::~Trophy()
{
}

void Trophy::animation()
{
	if (this->timer <= this->timerMax)
		this->timer++;

	if (this->timer >= 15)
	{
		this->timer = 0;

		switch (this->frame)
		{
		case 0:
			this->frame = 1;
			break;
		case 1:
			this->frame = 0;
			break;
		}

		this->sprite.setTextureRect(sf::IntRect(this->frame * 20, 0,
			20, 35));
	}
}

void Trophy::update()
{
	this->animation();
}
