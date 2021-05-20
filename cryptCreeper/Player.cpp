#include "Player.h"

void Player::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		0 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));

	this->lvl = 1;
	this->hp = 3;
	this->sword = 1;
	this->shield = 1;
	this->coin = 0;
	this->score = 0;
	this->posX = 400;
	this->posY = 800;
	this->movementArea[4][2] = 1;
	this->currentPos.x = 4;
	this->currentPos.y = 2;
	
	this->movementTimerMax = 5;
	this->movementTimer = this->movementTimerMax;
}

void Player::move()
{
	//Player can move up, down, right, left but cant go back
	if (this->movementTimer < this->movementTimerMax)
		this->movementTimer++;

	if (this->movementTimer >= this->movementTimerMax)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->posX > 0
			&& this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
		{
			this->posX -= 200;
			this->currentPos.y--;		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->posX < 800
			&& this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0)
		{
			this->posX += 200;
			this->currentPos.y++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->posY > 0
			&& this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0)
		{
			this->posY -= 200;
			this->currentPos.x--;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->posY < 800
			&& this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0)
		{
			this->posY += 200;
			this->currentPos.x++;
		}

		this->movementArea[this->currentPos.x][this->currentPos.y] = 1;
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

void Player::setScore(int score)
{
	this->score += score;
}

void Player::setHp(int hp)
{
	this->hp += hp;
}

void Player::setCoin(int coin)
{
	this->coin += coin;
}

bool Player::isDead()
{
	if (hp <= 0)
		return true;
	else return false;
}

int Player::getSword()
{
	return this->sword;
}

int Player::getShield()
{
	return this->shield;
}

int Player::getLvl()
{
	return this->lvl;
}

int Player::getHp()
{
	return this->hp;
}

int Player::getCoin()
{
	return this->coin;
}

int Player::getScore()
{
	return this->score;
}

void Player::setLvl(int lvl)
{
	if (this->lvl <= 9) //max level 10
		this->lvl += lvl;
}

void Player::setSword(int sword)
{
	this->sword += sword;
}

void Player::setShield(int shield)
{
	this->shield += shield;
}

void Player::update()
{
	this->isDead();
	this->move();
	this->sprite.setPosition(this->posX, this->posY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				std::cout << movementArea[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}
