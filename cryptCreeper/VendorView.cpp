#include "VendorView.h"

void VendorView::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->item1Text.setFont(this->font);

	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->vendorSprite.setTexture(this->texture);
	this->item1Sprite.setTexture(this->texture);
}

void VendorView::initVendor()
{
	//Background
	this->background.setFillColor(sf::Color(30, 30, 30));
	this->background.setOutlineColor(sf::Color::Black);
	this->background.setOutlineThickness(10.f);
	this->background.setSize(sf::Vector2f(800.f, 800.f));
	this->background.setPosition(sf::Vector2f(100.f, 100.f));

	//Sprites

	//Text
}

void VendorView::buttonsClick(sf::RenderWindow& target, State& state)
{
}

void VendorView::buttonsHover(sf::RenderWindow& target)
{
}

VendorView::VendorView()
{
	this->initVariables();
	this->initVendor();
}

VendorView::~VendorView()
{
}

void VendorView::update(sf::RenderWindow& target, State& state)
{
	this->buttonsHover(target);
	this->buttonsClick(target, state);
}

void VendorView::render(sf::RenderTarget& target)
{
	target.draw(this->background);
}
