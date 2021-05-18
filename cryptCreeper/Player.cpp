#include "Player.h"

void Player::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		0 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->posX = 400;
	this->posY = 800;

	this->hp = 3;
	this->dmg = 1;
	this->money = 0;
	this->score = 0;
	this->posX = 400;
	this->posY = 800;
	
	this->movementTimerMax = 5;
	this->movementTimer = this->movementTimerMax;
}

void Player::move()
{
	//Player can move only up, right, left 
	if (this->movementTimer < this->movementTimerMax)
		this->movementTimer++;

	if (this->movementTimer >= this->movementTimerMax)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->posX > 0)
			this->posX -= 200;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->posX < 800)
			this->posX += 200;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->posY > 0)
			this->posY -= 200;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->posY < 1000)
			this->posY += 200;

		this->movementTimer = 0;
	}
}

Player::Player()
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Player::~Player()
{
}

void Player::addScore(int score)
{
	this->score += score;
}

void Player::update()
{
	this->move();
	this->sprite.setPosition(this->posX, this->posY);
}
