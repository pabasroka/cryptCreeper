#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1000, 1300);
	this->window = new sf::RenderWindow(this->videoMode, "Crypt Creeper", sf::Style::Resize | sf::Style::Close);
	this->window->setFramerateLimit(60);
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
	this->window->clear();

	this->area->render(*this->window);

	this->window->display();
}
