#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Calculator.h"
#include "Field.h"

class Button
{
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	bool status = false;
public:
	Button(float, float, std::string);
	void setPosition(float x, float y);
	sf::Text& getText();
	sf::Text& getText2();
	sf::RectangleShape& getButton();
	sf::Vector2f getPosition();
	void push(Field*& field);
};

