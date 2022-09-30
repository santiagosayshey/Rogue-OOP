#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "../State/State.h"
#include "../State/PickState.h"
#include "../Entity/Player.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void run();
    void setState(State* newState);


private:
    sf::RenderWindow* window;
    State* currentState;

    Player* player;
};

#endif