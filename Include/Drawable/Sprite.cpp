#include "Sprite.h"
#include <iostream>

Sprite::Sprite(std::string texture, int x, int y, int width, int height, float scale)
{
    // take x,y values and store as current position
    this->x = x;
    this->y = y;

    // store size of sprite
    this->width = width;
    this->height = height;

    // set the sf::texture to be the parameter 'texture'
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texture);

    // use this texture for the displayed sprite
    sprite = new sf::Sprite;
    sprite->setTexture(*(this->texture));

    // set the current texture rect for dynamic sprites
    sprite->setTextureRect(sf::IntRect(0, 0, width, height));

    // change the size of the sprite to be drawn correctly in the render window
    sprite->setScale(scale, scale);

    // set the position of the sprite
    // position always called after scale to make sure everything is in correct pos
    sprite->setPosition(x, y);
}

Sprite::~Sprite()
{
    delete texture;
    delete sprite;
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(*sprite);
}

bool Sprite::checkCollision(sf::RenderWindow *window)
{
    // find the bounds of the mouse
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    // find the bounds of the current sprite
    sf::FloatRect bounds = sprite->getGlobalBounds();

    // return a boolean that defines whether the bounds of the sprite contains the bounds of the mouse
    return bounds.contains(mouse);
}

void Sprite::setPosition(int x, int y)
{
    sprite->setPosition(x, y);
}

int Sprite::getX()
{
    return x;
}

int Sprite::getY()
{
    return y;
}

void Sprite::flip()
{
    // set x to be negative values of itself, y stays the same
    // effectively mirrors the image
    sprite->scale(-1.f, 1.f);
}

sf::Sprite* Sprite::getSFSprite()
{
    return sprite;
}
