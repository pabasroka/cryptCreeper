#include "Game.h"

//Set width, height screen, app icon, view 
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1900, 1600);
	this->window = new sf::RenderWindow(this->videoMode, "Crypt Creeper", sf::Style::Resize | sf::Style::Close);
	this->view.setSize(1900, 1600);
	this->view.move(sf::Vector2f(0.f, 150.f));
	if (!this->icon.loadFromFile("Sprites/icon.png"))
		throw "Could not load icon \n";
	this->window->setView(this->view);
	this->window->setFramerateLimit(60);
	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
}

void Game::initGameOverStuff()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->gameOverText.setFont(this->font);

	this->gameOverText.setFont(font);
	this->gameOverText.setCharacterSize(160);
	this->gameOverText.setFillColor(sf::Color::White);
	this->gameOverText.setOutlineColor(sf::Color::Black);
	this->gameOverText.setOutlineThickness(10.f);
	this->gameOverText.setPosition(40, 200);
	this->gameOverText.setString("GAME   OVER ! \n\n    Press R \n     to restart !");

	//Background
	this->backgroundFog.setFillColor(sf::Color(20, 20, 20, 220));
	this->backgroundFog.setPosition(sf::Vector2f(-500.f, -300.f));
	this->backgroundFog.setSize(sf::Vector2f(2000, 2000));
}

void Game::initCursor()
{
	if (!this->cursorTexture.loadFromFile("Sprites/cursor.png"))
		throw "Could not load cursor \n";
	this->cursor.setTexture(this->cursorTexture);
	//this->window->setMouseCursorVisible(false);
	this->cursor.setScale(sf::Vector2f(5.f, 5.f));
}

void Game::reset()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		delete this->area;
		this->area = new Area();
	}
}

Game::Game()
{
	this->initWindow();
	this->initGameOverStuff();
	this->initCursor();
	this->area = new Area();
}

Game::~Game()
{
	delete this->window;
	delete this->area;
}

//Window interaction, Escape button
void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	if (this->area->endGame())
		this->area->update(*this->window);

	//Update cursor position
	this->cursor.setPosition(sf::Mouse::getPosition(*window).x , 
		sf::Mouse::getPosition(*window).y);

	//We can reset game at any time
	this->reset();
}

void Game::render()
{
	//Clear screen and set blue background color
	this->window->clear(sf::Color(3, 3, 28));

	//Render all of the objects
	this->area->render(*this->window);
	if (!this->area->endGame())
	{
		this->window->draw(this->backgroundFog);
		this->window->draw(this->gameOverText);
	}

	//Render custom cursor
	this->window->draw(this->cursor);

	//Display it
	this->window->display();
}
