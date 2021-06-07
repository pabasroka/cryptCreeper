#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "utilities.h"
#include "Player.h"

class VendorView
{
	//Shop view
	sf::Texture vendorTexture;
	sf::Texture texture;
	sf::Sprite vendorSprite;
	sf::Sprite item1Sprite;
	sf::Sprite item2Sprite;
	sf::Sprite item3Sprite;
	sf::RectangleShape background;
	sf::RectangleShape closeVendorButton;
	sf::RectangleShape item1Button;
	sf::RectangleShape item2Button;
	sf::RectangleShape item3Button;
	sf::Font font;
	sf::Text item1Text;
	sf::Text item2Text;
	sf::Text item3Text;
	sf::Text closeVendorText;

	int rectSize;

	void initVariables();
	void initVendor();
	void buttonsClick(sf::RenderWindow& target, State& state, Player& player);
	void buttonsHover(sf::RenderWindow& target, sf::RectangleShape& button);

public:
	VendorView();
	virtual ~VendorView();

	void update(sf::RenderWindow& target, State& state, Player& player);
	void render(sf::RenderTarget& target);
};

