#pragma once
#include "Area.h"

class Game
{
	//Window objects
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	sf::View view;
	sf::Image icon;

	//Area includes enemies, items, player etc.. 
	Area* area;

	void initWindow();

public:
	Game();
	virtual ~Game();

	//Functions
	void pollEvents();
	const bool running() const;

	//Render/update
	void update();
	void render();
};

