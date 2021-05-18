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
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->mouseClick(target);

	this->player.update();

	for (size_t i = 0; i < this->enemies.size(); i++)
		if (isPlayerIntersectSomething(this->player, this->enemies[i]))
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->player.addScore(100);
		}
	
}

void Area::render(sf::RenderTarget& target)
{
	//Render main board
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->render(target);

	for (size_t i = 0; i < enemies.size(); i++)
		this->enemies[i]->render(target);

	this->player.render(target);

	//Render bottom of screen
	this->hud.render(target);
}

bool isPlayerIntersectSomething(Player& player, Enemy* enemy)
{
	if (player.getPosition().x == enemy->getPosition().x &&
		player.getPosition().y == enemy->getPosition().y)
		return true;
	else
		return false;

}
