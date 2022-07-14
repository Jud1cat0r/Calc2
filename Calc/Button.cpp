#include "Button.h"


Button::Button(float width, float height, std::string name)
	: rectangle(sf::Vector2f(width, height))
{
	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{
		std::cout << "font not found";
	}
	text.setString(name);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(30);

	text2.setString(name);
	text2.setFont(font);
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(20);

	rectangle.setFillColor(sf::Color(20, 20, 20));
	rectangle.setOutlineColor(sf::Color(38, 38, 38));
	rectangle.setOutlineThickness(2);
}

void Button::setPosition(float x, float y)
{
	rectangle.setPosition(x, y);
	text.setPosition(x + 25, y + 12);
	text2.setPosition(x + 15, y + 2);
}

sf::Text& Button::getText()
{
	return text;
}

sf::Text& Button::getText2()
{
	return text2;
}

sf::RectangleShape& Button::getButton()
{
	return rectangle;
}

sf::Vector2f Button::getPosition()
{
	return rectangle.getPosition();
}

void Button::push(Field*& field)
{
	std::string str = text.getString();
	std::string strField = field->getText().getString();
	if (strField == "0") strField = "";
	strField += str;
	field->setField(strField);
}