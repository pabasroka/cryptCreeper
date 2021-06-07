#include "Portal.h"

void Portal::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(1 * this->rectSize / 3,
		1 * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	this->sprite.setPosition(this->posX + 24, this->posY + 12);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

	this->frame = 0;
	this->timerMax = 8;
	this->timer = this->timerMax;
}

Portal::Portal(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Portal::~Portal()
{
}

void Portal::animation()
{
	if (this->timer <= this->timerMax)
		this->timer++;

	if (this->timer >= 8)
	{
		this->timer = 0;

		switch (this->frame)
		{
		case 0:
			this->frame = 1;
			break;
		case 1:
			this->frame = 2;
			break;
		case 2:
			this->frame = 3;
			break;
		case 3:
			this->frame = 4;
			break;
		case 4:
			this->frame = 5;
			break;
		case 5:
			this->frame = 6;
			break;
		case 6:
			this->frame = 0;
			break;
		}

		this->sprite.setTextureRect(sf::IntRect(1 * this->rectSize / 3,
			this->frame * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	}
}

void Portal::update()
{
	this->animation();
}

