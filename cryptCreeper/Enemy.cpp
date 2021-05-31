#include "Enemy.h"

void Enemy::initVariables(int posX, int posY, int power)
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->text.setFont(this->font);

	this->power = power;
	this->frame = 0;

	this->sprite.setScale(sf::Vector2f(10.f, 10.f));
	this->sprite.setPosition(this->posX + 24, this->posY + 12);

	this->timerMax = 15;
	this->timer = this->timerMax;
	

	//Field text
	this->text.setCharacterSize(120);
	this->text.setPosition(sf::Vector2f(this->posX + 0, this->posY + 2 * this->rectSize));
	this->text.setFillColor(sf::Color::Red);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(8.f);
	this->text.setString(std::to_string(this->power));
}

//Change enemy sprite every few seconds
void Enemy::animation()
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
			this->frame = 2;
			break;
		case 2:
			this->frame = 0;
			break;
		}

		this->sprite.setTextureRect(sf::IntRect(4 * this->rectSize + this->power * 16,
			this->frame * this->rectSize / 3, this->rectSize / 3, this->rectSize / 3));
	}
}

Enemy::Enemy(int posX, int posY, int power)
	: Object(posX, posY)
{
	this->initVariables(posX, posY, power);
}

Enemy::~Enemy()
{
}

int Enemy::getPower()
{
	return this->power;
}

void Enemy::update()
{
	this->animation();
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->text);
}
