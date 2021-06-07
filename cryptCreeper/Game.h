#pragma once
#include "Area.h"
#include "MainMenu.h"
#include "Info.h"
#include "VendorView.h"

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

	//End game - trophy
	sf::Text endGameText;
	sf::RectangleShape backgroundFogWin;

	/* ====== STATES ====== */
	State state;
	//Area includes enemies, items, player etc.. 
	Area* area;
	//Main menu - first screen, that contains start, exit buttons
	MainMenu* mainMenu;
	//Info about the game
	Info* info;
	//Shop/vendor view
	VendorView* vendorView;

	//Player stats
	int score;

	//Cursor
	sf::Texture cursorTexture;
	sf::Sprite cursor;

	void initWindow();
	void initGameOverStuff();
	void initEndGameStuff();
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

