#include "Area.h"

void Area::initNewArea()
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			// create_enemy/cosinnego(new Enemy(i * 200, j * 200));
			fields.push_back(new Field(i * 200, j * 200, 200));
		}
	}
	enemies.push_back(new Enemy(400, 400));
	enemies.push_back(new Enemy(200, 200));
	coins.push_back(new Coin(600, 800));

	this->timerMax = 5;
	this->timer = this->timerMax;
}

Area::Area()
{
	this->initNewArea();
}

Area::~Area()
{
}

void Area::update(sf::RenderWindow& target)
{
	this->endGame();

	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->mouseClick(target);

	this->player.update();

	for (size_t i = 0; i < this->enemies.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->enemies[i]))
		{
			this->enemies.erase(this->enemies.begin() + i);
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
	}

}

void Area::render(sf::RenderTarget& target)
{
	//Render main board
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->render(target);

	for (size_t i = 0; i < enemies.size(); i++)
		this->enemies[i]->render(target);

	for (size_t i = 0; i < coins.size(); i++)
		this->coins[i]->render(target);

	this->player.render(target);

	//Render bottom of screen
	this->hud.render(target, this->player.getHp());
}

bool Area::endGame()
{
	if (!this->player.isDead())
		return true;
	else
		return false;
}

bool isPlayerIntersectSomething(Player& player, Enemy* enemy)
{
	if (player.getPosition().x == enemy->getPosition().x &&
		player.getPosition().y == enemy->getPosition().y)
		return true;
	else
		return false;

}
