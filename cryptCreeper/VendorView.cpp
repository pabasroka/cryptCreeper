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
	this->item1Sprite.setPosition(sf::Vector2f(150.f, 400.f));

	this->item2Sprite = this->item1Sprite;
	this->item2Sprite.setPosition(sf::Vector2f(400.f, 400.f));
	this->item2Sprite.setTextureRect(sf::IntRect(0, 2 * this->rectSize,
		this->rectSize, this->rectSize));

	this->item3Sprite = this->item1Sprite;
	this->item3Sprite.setTextureRect(sf::IntRect(2 * this->rectSize, 0,
		this->rectSize, this->rectSize));
	this->item3Sprite.setPosition(sf::Vector2f(680.f, 400.f));

	//Buttons
	this->closeVendorButton.setOutlineThickness(10.f);
	this->closeVendorButton.setSize(sf::Vector2f(300.f, 100.f));
	this->closeVendorButton.setPosition(sf::Vector2f(330.f, 750.f));

	this->item1Button.setOutlineThickness(10.f);
	this->item1Button.setSize(sf::Vector2f(100.f, 100.f));
	this->item1Button.setPosition(sf::Vector2f(180.f, 600.f));

	this->item2Button = this->item1Button;
	this->item2Button.setPosition(sf::Vector2f(430.f, 600.f));

	this->item3Button = this->item1Button;
	this->item3Button.setPosition(sf::Vector2f(710.f, 600.f));
	

	//Text
	this->item1Text.setCharacterSize(80);
	this->item1Text.setPosition(sf::Vector2f(this->item1Button.getPosition().x + 30,
		this->item1Button.getPosition().y));
	this->item1Text.setFillColor(sf::Color::Yellow);
	this->item1Text.setOutlineColor(sf::Color::Black);
	this->item1Text.setOutlineThickness(10.f);
	this->item1Text.setString("2");

	this->item2Text = this->item1Text;
	this->item2Text.setString("2");
	this->item2Text.setPosition(sf::Vector2f(this->item2Button.getPosition().x + 30,
		this->item2Button.getPosition().y));

	this->item3Text = this->item1Text;
	this->item3Text.setString("5");
	this->item3Text.setPosition(sf::Vector2f(this->item3Button.getPosition().x + 30,
		this->item3Button.getPosition().y));

	this->closeVendorText = this->item1Text;
	this->closeVendorText.setString("Leave");
	this->closeVendorText.setFillColor(sf::Color::White);
	this->closeVendorText.setPosition(sf::Vector2f(this->closeVendorButton.getPosition().x + 70,
		this->closeVendorButton.getPosition().y));
}

void VendorView::buttonsClick(sf::RenderWindow& target, State& state, Player& player)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 480,
		sf::Mouse::getPosition(target).y - 150);

	//Close vendor
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
		&& pos.x > this->closeVendorButton.getPosition().x
		&& pos.x < this->closeVendorButton.getPosition().x + this->closeVendorButton.getSize().x
		&& pos.y > this->closeVendorButton.getPosition().y
		&& pos.y < this->closeVendorButton.getPosition().y + this->closeVendorButton.getSize().y)
	{
		state = State::area;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	//Items
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Sword
		&& pos.x > this->item1Button.getPosition().x
		&& pos.x < this->item1Button.getPosition().x + this->item1Button.getSize().x
		&& pos.y > this->item1Button.getPosition().y
		&& pos.y < this->item1Button.getPosition().y + this->item1Button.getSize().y
		&& player.getCoin() >= 2)
	{
		player.addSword(1);
		player.setCoin(-2);
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Shield
		&& pos.x > this->item2Button.getPosition().x
		&& pos.x < this->item2Button.getPosition().x + this->item2Button.getSize().x
		&& pos.y > this->item2Button.getPosition().y
		&& pos.y < this->item2Button.getPosition().y + this->item2Button.getSize().y
		&& player.getCoin() >= 2)
	{
		player.addShield(1);
		player.setCoin(-2);
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) //Heart
		&& pos.x > this->item3Button.getPosition().x
		&& pos.x < this->item3Button.getPosition().x + this->item3Button.getSize().x
		&& pos.y > this->item3Button.getPosition().y
		&& pos.y < this->item3Button.getPosition().y + this->item3Button.getSize().y
		&& player.getCoin() >= 5)
	{
		player.addHp(1);
		player.setCoin(-5);
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
}

void VendorView::buttonsHover(sf::RenderWindow& target, sf::RectangleShape& button)
{
	sf::Vector2i pos = sf::Vector2i(sf::Mouse::getPosition(target).x - 430,
		sf::Mouse::getPosition(target).y - 150);

	//Button
	if (pos.x > button.getPosition().x
		&& pos.x < button.getPosition().x + button.getSize().x
		&& pos.y > button.getPosition().y
		&& pos.y < button.getPosition().y + button.getSize().y)
	{
		button.setFillColor(sf::Color(169, 169, 169));
		button.setOutlineColor(sf::Color::Black);
	}
	else
	{
		button.setFillColor(sf::Color(128, 128, 128));
		button.setOutlineColor(sf::Color(50, 50, 50));
	}
}

VendorView::VendorView()
{
	this->initVariables();
	this->initVendor();
}

VendorView::~VendorView()
{
}

void VendorView::update(sf::RenderWindow& target, State& state, Player& player)
{
	this->buttonsHover(target, this->closeVendorButton);
	this->buttonsHover(target, this->item1Button);
	this->buttonsHover(target, this->item2Button);
	this->buttonsHover(target, this->item3Button);
	this->buttonsClick(target, state, player);
}

void VendorView::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->vendorSprite);
	target.draw(this->item1Sprite);
	target.draw(this->item2Sprite);
	target.draw(this->item3Sprite);
	target.draw(this->closeVendorButton);
	target.draw(this->item1Button);
	target.draw(this->item2Button);
	target.draw(this->item3Button);
	target.draw(this->item1Text);
	target.draw(this->item2Text);
	target.draw(this->item3Text);
	target.draw(this->closeVendorText);
}
