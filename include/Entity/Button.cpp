#include "Button.h"

Button::Button(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y)
{ 
    // seg faults if fonts and texts are pointers????
    font.loadFromFile(f);
    text.setFont(font);
    text.setPosition(x,y);
    text.setCharacterSize(s);
    text.setFillColor(c);
    text.setStyle(style);
    text.setString(type);
}

Button::~Button()
{ }

bool Button::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    return bounds.contains(mouse);
}

bool Button::isClicked(sf::RenderWindow* window)
{
    if (checkCollision(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    return false;
}


void Button::update(sf::RenderWindow* window, Game* game)
{ 
    if (!checkCollision(window))  {
        text.setFillColor(sf::Color::Black);
    }
    else {
        text.setFillColor(sf::Color::Blue);
    }
}

void Button::draw(sf::RenderWindow* window)
{
    window->draw(text);
}




