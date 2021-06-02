#include "Field.h"

void Field::initVariables(int xPos, int yPos)
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		std::cout << "Could not load font \n";
	this->text.setFont(this->font);

	if (!this->texture.loadFromFile("Sprites/sprites.png"))
		throw "Could not load textures \n";
	this->sprite.setTexture(this->texture);
	this->rectSize = 48;

	this->xPos = xPos;
	this->yPos = yPos;
}

void Field::initField(int lvl)
{
	//Field parameters (sprites)
	int typeOfFields{};
	switch (lvl)
	{
	case 0: case 1: case 2: case 3: case 4:
		typeOfFields = 1;
		break;
	case 5: case 6: case 7: case 8:
		typeOfFields = 2;
		break;
	case 9: 
		typeOfFields = 3;
		break;
	default:
		typeOfFields = 3;
		break;
	}
	this->sprite.setTextureRect(sf::IntRect(typeOfFields * this->rectSize,
		rand() % 6 * this->rectSize, this->rectSize, this->rectSize));
	this->sprite.setScale(sf::Vector2f(4.f, 4.f));
	this->sprite.setPosition(sf::Vector2f(this->xPos, this->yPos));

	//Rectangle
	/*this->field.setSize(sf::Vector2f(this->size, this->size));
	this->field.setFillColor(sf::Color(3, 3, 28));
	this->field.setOutlineThickness(5.f);
	this->field.setOutlineColor(sf::Color(15, 64, 5));
	this->field.setPosition(sf::Vector2f(this->xPos, this->yPos));
	*/

	//Field text
	/*this->text.setCharacterSize(40);
	this->text.setPosition(sf::Vector2f(this->xPos + 10, this->yPos + 5));
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(1.f);*/

	//this->text.setString(std::to_string(getCounter()));
	//this->text.setString(std::to_string(xPos) + ":" + std::to_string(yPos));
}

Field::Field(int xPos, int yPos, int size, int lvl)
{
	this->initVariables(xPos, yPos);
	this->initField(lvl);
}

Field::~Field()
{
}

void Field::render(sf::RenderTarget& target)
{
	//target.draw(this->field);
	target.draw(this->sprite);
	//target.draw(this->text);
}
