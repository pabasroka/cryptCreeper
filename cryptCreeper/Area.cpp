#include "Area.h"

void Area::initNewArea()
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
			fields.push_back(new Field(i * 200, j * 200, 200));
	}
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
}

void Area::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < fields.size(); i++)
		this->fields[i]->render(target);

}
