#include "Coin.h"

void Coin::initVariables(int posX, int posY)
{
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));
	this->sprite.setOrigin(sf::Vector2f(8.f, 8.f));

	//Animation stuff
	this->reverse = true;
	this->frame = 4;
	this->timerMax = 15;
	this->timer = this->timerMax;
}


void Coin::animation()
{
	if (this->timer <= this->timerMax)
		this->timer++;

	if (this->timer >= 15)
	{
		this->timer = 0;

		switch (this->frame)
		{
		case 4:
			this->frame = 5;
			this->reverse ? this->reverse = false : this->reverse = true;
			break;
		case 5:
			this->reverse ? this->frame = 6 : this->frame = 4;
			break;
		case 6:
			this->reverse ? this->frame = 7 : this->frame = 5;
			break;
		case 7:
			this->reverse ? this->frame = 8 : this->frame = 6;
			break;
		case 8:
			this->frame = 7;
			this->reverse ? this->reverse = false : this->reverse = true;
			break;
		}

		this->sprite.setPosition(this->posX + 100, this->posY + 100);

		if (this->reverse)
			this->sprite.setScale(sf::Vector2f(-10.f, 10.f));
		else
			this->sprite.setScale(sf::Vector2f(10.f, 10.f));

		this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
			this->frame * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	}
}

Coin::Coin(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Coin::~Coin()
{
}

void Coin::update()
{
	this->animation();
}

