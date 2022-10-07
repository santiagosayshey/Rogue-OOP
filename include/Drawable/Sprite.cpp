#include "Sprite.h"
#include <iostream>

Sprite::Sprite(std::string texture, int x, int y, int size, int scale)

{
    this->size = size;
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texture);
    this->texture->setRepeated(true);

    sprite = new sf::Sprite;
    sprite->setTexture(*(this->texture));
    sprite->setTextureRect(sf::IntRect(0, 0, size, size));
    sprite->setScale(scale, scale);
    sprite->setOrigin(size / 2, size / 2);
    sprite->setPosition(x, y);

    currentFrame = 0;
    numFrames = 7;
    row = 0;
}

Sprite::~Sprite()
{
    delete texture;
    delete sprite;
}

void Sprite::update(sf::RenderWindow *window)
{
}

void Sprite::updateAnimation(int numFrames, int row)
{
    currentFrame = 0;
    this->numFrames = numFrames;
    this->row = row;
}

bool Sprite::checkCollision(sf::RenderWindow *window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = sprite->getGlobalBounds();

    return bounds.contains(mouse);
}

bool Sprite::animation(bool repeat)
{
    if (clock.getElapsedTime().asSeconds() > 0.1f)
    
    {
        clock.restart();

        if (currentFrame != numFrames)
        {
            if (currentFrame > 8)
            {
                sprite->setTextureRect(sf::IntRect(size * currentFrame, size * row + size, size, size));
                currentFrame++;
            }
            else
            {
                sprite->setTextureRect(sf::IntRect(size * currentFrame, size * row, size, size));
                currentFrame++;
            }
        }
        // reformat this
        else
        {
            if (repeat == true)
            {
                // set current frame to 0 IF the animation needs to be repeated
                currentFrame=0;
            }
            else
                // if not repeated, play idle animation
                updateAnimation(7, 0);
                return true;
        }
        
    }
    return false;
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(*sprite);
}

void Sprite::setPos(int x, int y)
{
    sprite->setPosition(x, y);
}

void Sprite::flip()
{
    sprite->scale(-1.f, 1.f);
}