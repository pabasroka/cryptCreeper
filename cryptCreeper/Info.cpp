#include "Info.h"

void Info::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->goBackText.setFont(this->font);

	if (!this->mouseTexture.loadFromFile("Sprites/mouse.png"))
		throw "Could not load textures \n";
	this->mouse.setTexture(this->mouseTexture);

	if (!this->keysTexture.loadFromFile("Sprites/keys.png"))
		throw "Could not load textures \n";
	this->keys.setTexture(this->keysTexture);
}

void Info::initInfo()
{
	//Background
	this->background.setFillColor(sf::Color(3, 3, 28));
	this->background.setSize(sf::Vector2f(1900, 1600));

	//Buttons
	this->goBackButton.setFillColor(sf::Color::Blue);
	this->goBackButton.setOutlineColor(sf::Color(251, 133, 0));
	this->goBackButton.setOutlineThickness(10.f);
	this->goBackButton.setSize(sf::Vector2f(400.f, 200.f));
	this->goBackButton.setPosition(sf::Vector2f(300.f, 1100.f));

	//Sprites
	this->mouse.setScale(sf::Vector2f(7.f, 7.f));
	this->keys.setScale(sf::Vector2f(7.f, 7.f));

	this->mouse.setPosition(sf::Vector2f(120.f, 200.f));
	this->keys.setPosition(sf::Vector2f(650.f, 200.f));

	//Text
	this->goBackText.setCharacterSize(100);
	this->goBackText.setPosition(sf::Vector2f(this->goBackButton.getPosition().x + 100,
		this->goBackButton.getPosition().y + 30));
	this->goBackText.setFillColor(sf::Color::White);
	this->goBackText.setOutlineColor(sf::Color::Black);
	this->goBackText.setOutlineThickness(10.f);
	this->goBackText.setString("Back");

	this->controlsText = this->goBackText;
	this->controlsText.setPosition(sf::Vector2f(350.f, 0.f));
	this->controlsText.setString("Controls:");

	this->mouseArrowsText = this->goBackText;
	this->mouseArrowsText.setCharacterSize(80);
	this->mouseArrowsText.setPosition(sf::Vector2f(300.f, 450.f));
	this->mouseArrowsText.setString("Mouse or arrows");

	this->rulesText = this->mouseArrowsText;
	this->mouseArrowsText.setCharacterSize(60);
	this->mouseArrowsText.setPosition(sf::Vector2f(0.f, 600.f));
	ss << "Your goal: achieve the highest possible score  \n\n" <<
		"* Collect swords and shields to defeat your enemies  \n" <<
		"* Portals   \n" <<
		"* You can buy cool stuff from vendor \n" <<
		"* Player cannot backtracking \n";
	this->mouseArrowsText.setString(this->ss.str());
}

void Info::buttonsClick(sf::RenderWindow& target, State& state)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& pos.x > this->goBackButton.getPosition().x
		&& pos.x < this->goBackButton.getPosition().x + this->goBackButton.getSize().x
		&& pos.y > this->goBackButton.getPosition().y
		&& pos.y < this->goBackButton.getPosition().y + this->goBackButton.getSize().y)
	{
		state = State::mainMenu;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void Info::buttonsHover(sf::RenderWindow& target)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	//Button
	if (pos.x > this->goBackButton.getPosition().x
		&& pos.x < this->goBackButton.getPosition().x + this->goBackButton.getSize().x
		&& pos.y > this->goBackButton.getPosition().y
		&& pos.y < this->goBackButton.getPosition().y + this->goBackButton.getSize().y)
	{
		this->goBackButton.setFillColor(sf::Color::Red);
		this->goBackButton.setOutlineColor(sf::Color(251, 233, 120));
	}
	else
	{
		this->goBackButton.setFillColor(sf::Color::Blue);
		this->goBackButton.setOutlineColor(sf::Color(251, 133, 0));
	}
}

Info::Info()
{
	this->initVariables();
	this->initInfo();
}

Info::~Info()
{
}

void Info::update(sf::RenderWindow& target, State& state)
{
	this->buttonsHover(target);
	this->buttonsClick(target, state);
}

void Info::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->mouse);
	target.draw(this->keys);
	target.draw(this->goBackButton);
	target.draw(this->goBackText);
	target.draw(this->controlsText);
	target.draw(this->mouseArrowsText);
	target.draw(this->rulesText);
}
