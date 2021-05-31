#include "Field.h"

int Field::counter = 0;

void Field::initVariables(int xPos, int yPos, int size)
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
	this->size = size;
}

void Field::initField(int lvl)
{
	//Field parameters (sprites)
	int typeOfFields{};
	switch (lvl)
	{
	case 0: case 1: case 2: case 3:
		typeOfFields = 1;
		break;
	case 4: case 5: case 6:
		typeOfFields = 2;
		break;
	case 7: 
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
	counter++;
	this->initVariables(xPos, yPos, size);
	this->initField(lvl);
}

Field::~Field()
{
}

void Field::mouseClick(sf::RenderWindow& target)
{
	//std::cout << "x: " << sf::Mouse::getPosition(target).x << "y: " << sf::Mouse::getPosition(target).y << "\n";
	sf::Vector2i mousePos = sf::Mouse::getPosition(target);

	if (mousePos.x < this->xPos + size && mousePos.x > this->xPos
		&& mousePos.y < this->yPos + size && mousePos.y > this->yPos)
		;
		//std::cout << "field[" << xPos << "][" << yPos << "] \n";
}

int Field::getCounter()
{
	return counter;
}

void Field::render(sf::RenderTarget& target)
{
	//target.draw(this->field);
	target.draw(this->sprite);
	//target.draw(this->text);
}
