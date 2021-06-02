#include "Area.h"

void Area::initFirstArea()
{
	this->initNewArea();
	
	this->timerMax = 5;
	this->timer = this->timerMax;
}

void Area::initNewArea()
{
	int portalPos = rand() % 5;

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			//create fields
			fields.push_back(new Field(i * 200, j * 200, 200, this->player.getLvl()));

			// create portal in first row 
			if (j == 0 && i == portalPos)
				portal = new Portal(i * 200, j * 200);
			else if (j != 4 || i != 2) // add objects (enemies, coins, items, etc)
				randomizer(i * 200, j * 200);
		}
	}
}

void Area::randomizer(int posX, int posY)
{
	bool condition = (rand() % 100) < 30;
	if (condition)
	{
		coins.push_back(new Coin(posX, posY));
		return;
	}

	condition = (rand() % 100) < 20;
	if (condition)
	{
		swords.push_back(new Sword(posX, posY));
		return;
	}

	condition = (rand() % 100) < 10;
	if (condition)
	{
		shields.push_back(new Shield(posX, posY));
		return;
	}

	// If the previous conditions doesn't run
	int randomEnemy = rand() % this->player.getLvl();

	switch (randomEnemy)
	{
	case 0: case 1: 
		enemies.push_back(new Enemy(posX, posY, 1));
		break;
	case 2:
		enemies.push_back(new Enemy(posX, posY, 2));
		break;
	case 3:
		enemies.push_back(new Enemy(posX, posY, 3));
		break;
	case 4:
		enemies.push_back(new Enemy(posX, posY, 4));
		break;
	case 5:
		enemies.push_back(new Enemy(posX, posY, 5));
		break;
	case 6:
		enemies.push_back(new Enemy(posX, posY, 6));
		break;
	case 7:
		enemies.push_back(new Enemy(posX, posY, 7));
		break;
	case 8:
		enemies.push_back(new Enemy(posX, posY, 8));
		break;
	case 9:
		enemies.push_back(new Enemy(posX, posY, 9));
		break;
	case 10: default:
		enemies.push_back(new Enemy(posX, posY, 10));
		break;
	}
}

bool isPlayerIntersectSomething(Player& player, Object* object)
{
	if (player.getPosition().x == object->getPosition().x &&
		player.getPosition().y == object->getPosition().y)
		return true;
	else
		return false;
}

Area::Area()
{
	this->initFirstArea();
}

Area::~Area()
{
}

bool Area::endGame()
{
	if (!this->player.isDead())
		return true;
	else
		return false;
}

void Area::update(sf::RenderWindow& target)
{
	this->endGame();

	this->player.update(target);

	//Player entered the portal
	if (isPlayerIntersectSomething(this->player, this->portal))
	{
		this->enemies.clear();
		this->coins.clear();
		this->shields.clear();
		this->swords.clear();
		this->fields.clear();

		this->player.nextAreaSettings();
		this->initNewArea();
	}

	int scoreDrop = rand() % this->player.getLvl() * 50 + this->player.getLvl() * 20;

	this->portal->animation();

	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->update();
		if (isPlayerIntersectSomething(this->player, this->enemies[i]))
		{
			this->player.setScore(scoreDrop);
			this->player.setHp(this->enemies[i]->getPower());
			this->enemies.erase(this->enemies.begin() + i); 
		}
	}

	//Check if player intersect with sth
	for (size_t i = 0; i < this->coins.size(); i++)
	{
		this->coins[i]->update();
		if (isPlayerIntersectSomething(this->player, this->coins[i]))
		{
			this->player.setCoin(1);
			this->player.setScore(scoreDrop);
			this->coins.erase(this->coins.begin() + i);
		}
	}
	for (size_t i = 0; i < this->swords.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->swords[i]))
		{
			this->player.setSword(this->swords[i]->getDmg());
			this->player.setScore(scoreDrop);
			this->swords.erase(this->swords.begin() + i);
		}
	for (size_t i = 0; i < this->shields.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->shields[i]))
		{		
			this->player.setShield(this->shields[i]->getArmor());
			this->player.setScore(scoreDrop);
			this->shields.erase(this->shields.begin() + i);
		}

	// User interface stats text
	this->hud.setText(this->player.getSword(), this->player.getShield(),
		this->player.getCoin(), this->player.getScore());


	//dev tools
	if (this->timer <= this->timerMax)
		this->timer++;

	if (this->timer >= 5)
	{
		this->timer = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			this->player.setHp(-1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			this->player.setCoin(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			this->player.setSword(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			this->player.setShield(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			this->player.setLvl(1);
			std::cout << this->player.getLvl();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			this->player.showMovementArea();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			this->player.setHp(5);
	}

}

void Area::render(sf::RenderTarget& target)
{
	//Render bottom of screen
	this->hud.render(target, this->player.getHp());

	//Render main board
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->render(target);

	//Render objects
	for (size_t i = 0; i < enemies.size(); i++)
		this->enemies[i]->render(target);
	for (size_t i = 0; i < coins.size(); i++)
		this->coins[i]->render(target);
	for (size_t i = 0; i < swords.size(); i++)
		this->swords[i]->render(target);
	for (size_t i = 0; i < shields.size(); i++)
		this->shields[i]->render(target);

	this->portal->render(target);

	this->player.render(target);
}