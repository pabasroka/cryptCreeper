#pragma once
#include "Area.h"

class Game
{
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	Area* area;

	void initWindow();

public:
	Game();
	virtual ~Game();

	void pollEvents();
	const bool running() const;

	void update();
	void render();
};

