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

	void initVariable();
	void initHUD();

public:
	HUD();
	virtual ~HUD();

	void render(sf::RenderTarget& target);
};

