#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Field
{
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
public:
	Field(float, float, std::string);
	void setPosition(float x, float y);
	sf::Text& getText();
	sf::RectangleShape& getField();
	void setField(std::string);
};

