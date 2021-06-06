#include "VendorView.h"

void VendorView::initVariables()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		throw "Could not load font \n";
	this->item1Text.setFont(this->font);

	if (!this->vendorTexture.loadFromFile("Sprites/vendor.png"))
		throw "Could not load textures \n";
	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->vendorSprite.setTexture(this->vendorTexture);
	this->item1Sprite.setTexture(this->texture);

	this->rectSize = 16;
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
	this->vendorSprite.setScale(sf::Vector2f(5.f, 5.f));
	this->vendorSprite.setPosition(sf::Vector2f(380.f, 100.f));

	this->item1Sprite.setTextureRect(sf::IntRect(0, 1 * this->rectSize, 
		this->rectSize, this->rectSize));
	this->item1Sprite.setScale(sf::Vector2f(10.f, 10.f));
	this->item1Sprite.setPosition(sf::Vector2f(150.f, 500.f));

	this->item2Sprite = this->item1Sprite;
	this->item2Sprite.setPosition(sf::Vector2f(400.f, 500.f));
	this->item2Sprite.setTextureRect(sf::IntRect(0, 2 * this->rectSize,
		this->rectSize, this->rectSize));

	this->item3Sprite = this->item1Sprite;
	this->item3Sprite.setTextureRect(sf::IntRect(0, 3 * this->rectSize,
		this->rectSize, this->rectSize));
	this->item3Sprite.setPosition(sf::Vector2f(680.f, 500.f));

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
	target.draw(this->vendorSprite);
	target.draw(this->item1Sprite);
	target.draw(this->item2Sprite);
	target.draw(this->item3Sprite);
}
