#pragma once
#include "Field.h"

class Area
{
	std::vector<Field*> fields;
	void initNewArea();

public:
	Area();
	virtual ~Area();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

