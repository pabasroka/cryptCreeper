#include "HUD.h"

void HUD::initVariable()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->swordText.setFont(this->font);
	this->shieldText.setFont(this->font);
	this->coinText.setFont(this->font);
	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sword.setTexture(this->texture);
	this->shield.setTexture(this->texture);
	this->heart.setTexture(this->texture);
	this->coin.setTexture(this->texture);
	this->rectSize = 16;
}

void HUD::initHUD()
{
	//Background
	this->background.setSize(sf::Vector2f(1000.f, 300.f));
	this->background.setFillColor(sf::Color(3, 3, 28));
	this->background.setPosition(sf::Vector2f(0.f, 1000.f));

	//Sprites
	this->sword.setTextureRect(sf::IntRect(0 * this->rectSize, 1 * this->rectSize,
		this->rectSize, this->rectSize));
	this->shield.setTextureRect(sf::IntRect(0 * this->rectSize, 2 * this->rectSize,
		this->rectSize, this->rectSize));
	this->heart.setTextureRect(sf::IntRect(0 * this->rectSize, 3 * this->rectSize,
		this->rectSize, this->rectSize));
	this->coin.setTextureRect(sf::IntRect(0 * this->rectSize, 4 * this->rectSize,
		this->rectSize, this->rectSize));

	this->sword.setScale(sf::Vector2f(8.f, 8.f));
	this->shield.setScale(sf::Vector2f(8.f, 8.f));
	this->heart.setScale(sf::Vector2f(8.f, 8.f));
	this->coin.setScale(sf::Vector2f(8.f, 8.f));

	this->heart.setPosition(sf::Vector2f(20.f, 1020.f));
	this->sword.setPosition(sf::Vector2f(120.f, 1150.f));
	this->shield.setPosition(sf::Vector2f(450.f, 1150.f));
	this->coin.setPosition(sf::Vector2f(780.f, 1150.f));


	//Text
	this->swordText.setCharacterSize(120);
	this->swordText.setPosition(sf::Vector2f(20.f, 1150.f));
	this->swordText.setFillColor(sf::Color::White);
	this->swordText.setOutlineColor(sf::Color::Black);
	this->swordText.setOutlineThickness(8.f);

	this->shieldText = this->swordText;
	this->shieldText.setPosition(sf::Vector2f(350.f, 1150.f));
	
	this->coinText = this->swordText;
	this->coinText.setPosition(sf::Vector2f(680.f, 1150.f));	

	this->scoreText = this->swordText;
	this->scoreText.setCharacterSize(80);
	this->scoreText.setPosition(sf::Vector2f(600.f, 1020.f));
}

HUD::HUD()
{
	this->initVariable();
	this->initHUD();
	this->setText(swordValue, shieldValue, coinValue, scoreValue);
}

HUD::~HUD()
{
}

void HUD::setText(int sword, int shield, int coin, int scoreValue)
{
	this->swordText.setString(std::to_string(sword));
	this->shieldText.setString(std::to_string(shield));
	this->coinText.setString(std::to_string(coin));
	this->scoreText.setString("Score: " +  std::to_string(scoreValue));
}

void HUD::render(sf::RenderTarget& target, int hearts)
{
	target.draw(this->background);
	target.draw(this->sword);
	target.draw(this->shield);
	target.draw(this->coin);
	target.draw(this->swordText);
	target.draw(this->shieldText);
	target.draw(this->coinText);
	target.draw(this->scoreText);

	switch (hearts)
	{
	case 1:
		this->heart.setPosition(sf::Vector2f(120.f, 1020.f));
		target.draw(this->heart);
		break;
	case 2:
		this->heart.setPosition(sf::Vector2f(120.f, 1020.f));
		target.draw(this->heart);
		this->heart.setPosition(sf::Vector2f(200.f, 1020.f));
		target.draw(this->heart);
		break;
	case 3:
		this->heart.setPosition(sf::Vector2f(120.f, 1020.f));
		target.draw(this->heart);
		this->heart.setPosition(sf::Vector2f(200.f, 1020.f));
		target.draw(this->heart);
		this->heart.setPosition(sf::Vector2f(280.f, 1020.f));
		target.draw(this->heart);
		break;
	}
}
