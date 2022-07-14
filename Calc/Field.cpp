#include "Field.h"

Field::Field(float width, float height, std::string name)
    :rectangle(sf::Vector2f(width, height))
{
    if (!font.loadFromFile("Resources/Fonts/arial.ttf"))
    {
        std::cout << "font not found";
    }
    text.setString(name);
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color(38, 38, 38));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(2);

}

void Field::setPosition(float x, float y)
{
    rectangle.setPosition(x, y);
    text.setPosition(x + 10, y);
}

sf::Text& Field::getText()
{
    return text;
}

sf::RectangleShape& Field::getField()
{
    return rectangle;
}

void Field::setField(std::string str)
{
    text.setString(str);
}