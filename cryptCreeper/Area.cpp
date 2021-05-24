#include "Area.h"

void Area::initFirstArea()
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			//create fields
			fields.push_back(new Field(i * 200, j * 200, 200));
		}
	}

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
			//create portal 
			if (j == 0 && i == portalPos)
				portal = new Portal(i * 200, j * 200);
			else //add objects (enemies, coins, items, etc)
				randomizer(i * 200, j * 200);
		}
	}
}

void Area::randomizer(int posX, int posY)
{
	int randomNumber = rand() % 100;

	if (randomNumber >= 0 && randomNumber <= 50) //enemy
	{
		//inside next randomizer (enemy power level)
		int randomEnemy = rand() % this->player.getLvl();

		switch (randomEnemy)
		{
			case 1: default:
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
			case 10:
				enemies.push_back(new Enemy(posX, posY, 10));
				break;
		}
		
	}
	else if (randomNumber > 50 && randomNumber <= 100) //coin
	{
		coins.push_back(new Coin(posX, posY));
	}
	/*else if (randomNumber > 30 && randomNumber <= 70) //
	{
	}
	else if (randomNumber > 70 && randomNumber <= 85)
	{
	}
	else if (randomNumber > 85 && randomNumber <= 90)
	{

	}
	else if (randomNumber > 90 && randomNumber <= 95)
	{
	}
	else if (randomNumber > 95 && randomNumber <= 100)
	{
	}*/
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

	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->mouseClick(target);

	this->player.update();

	if (isPlayerIntersectSomething(this->player, this->portal))
	{
		this->enemies.clear();
		this->coins.clear();
		this->player.nextAreaSettings();
		this->initNewArea();
	}

	for (size_t i = 0; i < this->enemies.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->enemies[i]))
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->player.setScore(100);
		}

	for (size_t i = 0; i < this->coins.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->coins[i]))
		{
			this->coins.erase(this->coins.begin() + i);
			this->player.setCoin(2);
			this->player.setScore(100);
		}

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
	}

}

void Area::render(sf::RenderTarget& target)
{
	//Render bottom of screen
	this->hud.render(target, this->player.getHp());

	//Render main board
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->render(target);

	for (size_t i = 0; i < enemies.size(); i++)
		this->enemies[i]->render(target);

	for (size_t i = 0; i < coins.size(); i++)
		this->coins[i]->render(target);

	this->portal->render(target);

	this->player.render(target);
}