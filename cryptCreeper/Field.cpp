#include "Field.h"

int Field::counter = 0;

void Field::initVariables(int xPos, int yPos, int size)
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		std::cout << "Could not load font \n";
	this->text.setFont(this->font);

	this->xPos = xPos;
	this->yPos = yPos;
	this->size = size;
}

void Field::initField()
{
	//Field parameters
	this->field.setSize(sf::Vector2f(this->size, this->size));
	this->field.setFillColor(sf::Color::Green);
	this->field.setOutlineThickness(5.f);
	this->field.setOutlineColor(sf::Color::Blue);
	this->field.setPosition(sf::Vector2f(this->xPos, this->yPos));

	//Field text
	this->text.setCharacterSize(40);
	this->text.setPosition(sf::Vector2f(this->xPos + 10, this->yPos + 5));
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(1.f);

	//this->text.setString(std::to_string(getCounter()));
	this->text.setString(std::to_string(xPos) + ":" + std::to_string(yPos));
}

Field::Field(int xPos, int yPos, int size)
{
	counter++;
	this->initVariables(xPos, yPos, size);
	this->initField();
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
		std::cout << "field[" << xPos << "][" << yPos << "] \n";
}

int Field::getCounter()
{
	return counter;
}

void Field::render(sf::RenderTarget& target)
{
	target.draw(this->field);
	target.draw(this->text);
}
