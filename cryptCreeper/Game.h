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

	//Game over text
	sf::Font font;
	sf::Text gameOverText;
	sf::RectangleShape backgroundFog;

	//Area includes enemies, items, player etc.. 
	Area* area;

	//States
	int state;

	//Cursor
	sf::Texture cursorTexture;
	sf::Sprite cursor;

	void initWindow();
	void initGameOverStuff();
	void initCursor();
	void reset();

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

