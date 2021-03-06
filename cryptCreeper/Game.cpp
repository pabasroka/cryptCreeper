#include "Game.h"

//Set width, height screen, app icon, view 
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1900, 1500);
	this->window = new sf::RenderWindow(this->videoMode, "Crypt Creeper", sf::Style::Close);
	this->view.setSize(1900, 1500);
	this->view.move(sf::Vector2f(0.f, 150.f));
	if (!this->icon.loadFromFile("Sprites/icon.png"))
		throw "Could not load icon \n";
	this->window->setView(this->view);
	this->window->setFramerateLimit(60);
	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());

	this->state = State::mainMenu;
	this->score = 0;
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
	this->gameOverText.setPosition(20, 0);

	//Background
	this->backgroundFog.setFillColor(sf::Color(20, 20, 20, 220));
	this->backgroundFog.setPosition(sf::Vector2f(-500.f, -300.f));
	this->backgroundFog.setSize(sf::Vector2f(2000, 2000));
}

void Game::initEndGameStuff()
{
	this->endGameText = this->gameOverText;
	this->endGameText.setFillColor(sf::Color(0, 165, 255));

	//Background
	this->backgroundFogWin.setFillColor(sf::Color(0, 165, 255, 180));
	this->backgroundFogWin.setPosition(sf::Vector2f(-500.f, -300.f));
	this->backgroundFogWin.setSize(sf::Vector2f(2000, 2000));
}

void Game::initCursor()
{
	if (!this->cursorTexture.loadFromFile("Sprites/cursor.png"))
		throw "Could not load cursor \n";
	this->cursor.setTexture(this->cursorTexture);
	this->window->setMouseCursorVisible(false);
	this->cursor.setScale(sf::Vector2f(5.f, 5.f));
}

void Game::highScoreToFile()
{
	std::fstream file;
	std::string line;
	
	file.open("score.txt", std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			this->oldScore = stoi(line);
		}
	}
	file.close();

	this->score = this->area->getPlayer().getScore();

	if (this->score > this->oldScore)
	{
		file.open("score.txt", std::ios::out);
		if (file.is_open())
		{
			file << this->score;
		}
		file.close();
	}
}

void Game::reset()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		delete this->area;
		this->area = new Area();
		this->state = State::area;
	}
}

Game::Game()
{
	this->initWindow();
	this->initGameOverStuff();
	this->initEndGameStuff();
	this->initCursor();
	this->mainMenu = new MainMenu();
	this->info = new Info();
	this->area = new Area();
	this->vendorView = new VendorView();
}

Game::~Game()
{
	delete this->window;
	delete this->area;
	delete this->mainMenu;
	delete this->info;
	delete this->vendorView;
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
			{
				this->mainMenu->update(*this->window, this->state);
				this->state = State::mainMenu;
				delete this->area;
				this->area = new Area();
			}
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
	if (this->area->endGame() && this->state == State::area)
		this->area->update(*this->window, this->state);

	//Update state
	if (this->state == State::mainMenu)
		this->mainMenu->update(*this->window, this->state);
	if (this->state == State::info)
		this->info->update(*this->window, this->state);
	if (this->state == State::vendor)
	{
		this->vendorView->update(*this->window, this->state, this->area->getPlayer());
		this->area->updateHud();
	}
	if (this->state == State::gameOver)
	{
		this->highScoreToFile();
	}

	//Update cursor position
	this->cursor.setPosition(sf::Mouse::getPosition(*window).x - 450, 
		sf::Mouse::getPosition(*window).y - 150);

	//Update score text
	this->score = this->area->getPlayer().getScore();
	this->gameOverText.setString("GAME   OVER ! \n\nScore: " + std::to_string(this->score)
		+ "\n\nPress R \n     to restart !");
	this->endGameText.setString("YOU   WIN ! \n\nScore: " + std::to_string(this->score)
		+ "\n\nPress R \n     to restart !");

	//We can reset game at any time
	this->reset();
}

void Game::render()
{
	//Clear screen and set blue background color
	this->window->clear(sf::Color(3, 3, 28));

	if (!this->area->endGame())
		this->state = State::gameOver;

	switch (this->state)
	{
	case State::mainMenu:
		this->mainMenu->render(*this->window);
		break;
	case State::area:
		//Render all of the objects
		this->area->render(*this->window);
		break;
	case State::info:
		this->info->render(*this->window);
		break;
	case State::gameOver:
		this->area->render(*this->window);
		this->window->draw(this->backgroundFog);
		this->window->draw(this->gameOverText);
		break;
	case State::vendor:
		this->area->render(*this->window);
		this->vendorView->render(*this->window);
		break;
	case State::exit:
		this->window->close();
		break;
	case State::trophy:
		this->area->render(*this->window);
		this->window->draw(this->backgroundFogWin);
		this->window->draw(this->endGameText);
		break;
	}

	//Render custom cursor
	this->window->draw(this->cursor);

	//Display it
	this->window->display();
}
