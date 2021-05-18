#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class HUD
{
	int rectSize;
	sf::RectangleShape background;
	sf::Texture texture;
	sf::Sprite sword;
	sf::Sprite shield;
	sf::Sprite heart;
	sf::Sprite coin;

	sf::Font font;
	sf::Text swordText;
	sf::Text shieldText;
	sf::Text coinText;
	sf::Text scoreText;

	int swordValue;
	int shieldValue;
	int coinValue;
	int scoreValue;

	void initVariable();
	void initHUD();

public:
	HUD();
	virtual ~HUD();

	void setText(int swordValue = 0, int shieldValue = 0, int coinValue = 0, int scoreValue = 0);

	void render(sf::RenderTarget& target, int hearts);
};

