#pragma once
#include <SFML/Graphics.hpp>
#include "utilities.h"

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
	sf::Font font;
	sf::Text item1Text;
	sf::Text item2Text;
	sf::Text item3Text;

	int rectSize;

	void initVariables();
	void initVendor();
	void buttonsClick(sf::RenderWindow& target, State& state);
	void buttonsHover(sf::RenderWindow& target);

public:
	VendorView();
	virtual ~VendorView();

	void update(sf::RenderWindow& target, State& state);
	void render(sf::RenderTarget& target);
};

