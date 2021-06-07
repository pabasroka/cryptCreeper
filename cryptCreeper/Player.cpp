#include "Player.h"

void Player::initVariables(int posX, int posY)
{
	this->sprite.setTextureRect(sf::IntRect(0 * this->rectSize,
		0 * this->rectSize, this->rectSize / 3, this->rectSize / 3));

	this->sprite.setPosition(this->posX + 24, this->posY + 12);
	this->sprite.setScale(sf::Vector2f(10.f, 10.f));

	this->lvl = 1;
	this->hp = 3;
	this->sword = 1;
	this->shield = 1;
	this->coin = 0;
	this->score = 0;

	this->nextAreaSettings();
	
	this->movementTimerMax = 7;
	this->movementTimer = this->movementTimerMax;
}

void Player::move(sf::RenderWindow& target)
{
	//Player can move up, down, right, left but cant go back
	if (this->movementTimer < this->movementTimerMax)
		this->movementTimer++;

	if (this->isAnyLegitMove())
	{
		if (this->movementTimer >= this->movementTimerMax)
		{
			this->moveKeyboard();
			this->moveMouse(target);

			this->movementArea[this->currentPos.x][this->currentPos.y] = 1;
			this->movementTimer = 0;
		}
	}
	else
		this->hp = 0;
}

void Player::moveKeyboard()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->posX > 0
		&& this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
	{
		this->posX -= 200;
		this->currentPos.y--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->posX < 800
		&& this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0)
	{
		this->posX += 200;
		this->currentPos.y++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->posY > 0
		&& this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0)
	{
		this->posY -= 200;
		this->currentPos.x--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->posY < 800
		&& this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0)
	{
		this->posY += 200;
		this->currentPos.x++;
	}
}

void Player::moveMouse(sf::RenderWindow& target)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		std::cout << pos.x << " : " << pos.y << "\n";

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Center
		&& pos.x > this->posX && pos.x < this->posX + 200
		&& pos.y > this->posY && pos.y < this->posY + 200)
		return;
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Left
		&& pos.x < this->posX && this->posX > 0
		&& pos.y > this->posY && pos.y < this->posY + 200
		&& this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
	{
		this->posX -= 200;
		this->currentPos.y--;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Right
		&& pos.x > this->posX && this->posX < 800
		&& pos.y > this->posY && pos.y < this->posY + 200
		&& this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0)
	{
		this->posX += 200;
		this->currentPos.y++;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Up
		&& pos.y < this->posY && this->posY > 0
		&& pos.x > this->posX && pos.x < this->posX + 200
		&& this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0)
	{
		this->posY -= 200;
		this->currentPos.x--;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Down
		&& pos.y > this->posY && this->posY < 800
		&& pos.x > this->posX && pos.x < this->posX + 200
		&& this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0)
	{
		this->posY += 200;
		this->currentPos.x++;
	}
}

void Player::nextAreaSettings()
{
	this->posX = 400;
	this->posY = 800;
	this->clearMovementArea();
	this->movementArea[4][2] = 1;
	this->currentPos.x = 4;
	this->currentPos.y = 2;
	this->lvl++;
}

bool Player::isAnyLegitMove()
{
	// top left, top right, bottom left, bottom right fields
	if ((this->currentPos.x == 0 && this->currentPos.y == 0) &&
		(this->movementArea[1][0] == 1 && this->movementArea[0][1] == 1))
		return false;
	else if ((this->currentPos.x == 0 && this->currentPos.y == 4) &&
		(this->movementArea[1][4] == 1 && this->movementArea[0][3] == 1))
		return false;
	else if ((this->currentPos.x == 4 && this->currentPos.y == 0) &&
		(this->movementArea[3][0] == 1 && this->movementArea[4][1] == 1))
		return false;
	else if ((this->currentPos.x == 4 && this->currentPos.y == 4) &&
		(this->movementArea[4][3] == 1 && this->movementArea[3][4] == 1))
		return false;
	else
	{
		// Center fields
		if (this->currentPos.x < 4 && this->currentPos.x > 0
			&& this->currentPos.y < 4 && this->currentPos.y > 0) 
		{
			if (this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0
				|| this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0
				|| this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0
				|| this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
				return true;
			else
				return false;
		}
		else
		{
			// last row
			if (this->currentPos.x == 4) 
			{
				if ( this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
					return true;
				else
					return false;
			}
			//first row
			else if (this->currentPos.x == 0) 
			{
				if (this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
					return true;
				else
					return false;
			}
			//left column
			else if (this->currentPos.y == 0) 
			{
				if (this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y + 1] == 0)
					return true;
				else
					return false;
			}
			//right column
			else if (this->currentPos.y == 4) 
			{
				if (this->movementArea[this->currentPos.x + 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x - 1][this->currentPos.y] == 0
					|| this->movementArea[this->currentPos.x][this->currentPos.y - 1] == 0)
					return true;
				else
					return false;
			}
		}
	}
}

// Constructor / destructor
Player::Player(int posX, int posY)
	: Object(posX, posY)
{
	this->initVariables(posX, posY);
}

Player::~Player()
{
}

void Player::showMovementArea()
{
	std::cout << "\n=========================\n";
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
			std::cout << this->movementArea[i][j] << " ";
		std::cout << "\n";
	}
}

void Player::clearMovementArea()
{
	for (size_t i = 0; i < 5; i++)
		for (size_t j = 0; j < 5; j++)
			this->movementArea[i][j] = 0;
}

// Getters / setters
void Player::setScore(int score)
{
	this->score += score;
}

void Player::setHp(int hp)
{
	this->hp = hp;
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

void Player::setPosition(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Player::addHp(int hp)
{
	if (hp >= 0)
	{
		if (this->hp < 3)
			this->hp += hp;
	}
	else
		this->hp += hp;
}

void Player::addSword(int sword)
{
	this->sword += sword;
}

void Player::addShield(int shield)
{
	this->shield += shield;
}

void Player::addHeart(int heart)
{
	if (this->hp < 3)
		this->hp += heart;
}

void Player::takeDamage(int damage)
{
	if (this->sword > 0)
	{
		int attack = this->sword;
		if (this->sword >= damage)
		{
			this->sword -= damage;
			damage -= attack;
		}
		else
		{
			this->sword = 0;
			damage -= attack;
		}
	}

	if (damage > 0)
	{
		if (this->shield > 0)
		{
			int attack2 = this->shield;
			if (this->shield >= damage)
			{
				this->shield -= damage;
				damage -= attack2;
			}
			else
			{
				this->shield = 0;
				damage -= attack2;
			}
		}
	}

	if (damage > 0)
	{
		this->hp -= damage;
	}
}

void Player::update(sf::RenderWindow& target)
{
	this->isDead();
	this->move(target);
	this->sprite.setPosition(this->posX, this->posY);
}
