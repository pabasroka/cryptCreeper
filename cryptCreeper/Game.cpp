#include "Game.h"

//Set width, height screen, app icon, view 
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1600, 1300);
	this->window = new sf::RenderWindow(this->videoMode, "Crypt Creeper", sf::Style::Resize | sf::Style::Close);
	this->view.setSize(1600, 1300);
	this->view.move(sf::Vector2f(-30.f, 150.f));
	this->icon.loadFromFile("Sprites/icon.png");
	this->window->setView(this->view);
	this->window->setFramerateLimit(60);
	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
}

Game::Game()
{
	this->initWindow();
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
	else
		std::cout << "GAME OVER";
}

void Game::render()
{
	//Clear screen and set blue background color
	this->window->clear(sf::Color(3, 3, 28));

	//Render all of the objects
	this->area->render(*this->window);

	//Display it
	this->window->display();
}
