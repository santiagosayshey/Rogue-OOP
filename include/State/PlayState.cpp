#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"

PlayState::PlayState(Game* game):
State(game)
{
    wizard   = new Human("assets/entity/human/MAGE.png",150,50);
    paladin  = new Human("assets/entity/human/PALADIN.png",650,50);
    necrom   = new Human("assets/entity/human/NECROMANCER.png",1150,50);

    melee    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "MELEE", 320, 800, 2);
    range    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "RANGE", 640, 800, 2);
    die      = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "DIE", 960, 800, 2);
    idle     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "IDLE", 1280, 800, 2);
    walk     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "WALK", 1500, 800, 2);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{

    // events
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            game->setState(new MenuState(game));
        }
    }

    melee   ->update(window, game);
    range   ->update(window, game);
    die     ->update(window, game);
    idle    ->update(window, game);
    walk    ->update(window, game);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (wizard->checkCollision(window))
        { wizard->updateSprite(8,1);
          paladin->updateSprite(8,1);
          necrom->updateSprite(8,1); }

        if (melee->checkCollision(window))
        { wizard->updateSprite(8,3);
          paladin->updateSprite(7,3);
          necrom->updateSprite(6,3); }

        if (range->checkCollision(window))
        { wizard->updateSprite(8,4);
          paladin->updateSprite(7,4);
          necrom->updateSprite(5,4); }

        if (die->checkCollision(window))
        { wizard->updateSprite(8,8);
          paladin->updateSprite(8,6);
          necrom->updateSprite(8,6); }

        if (idle->checkCollision(window))
        { wizard->updateSprite(10,4);
          paladin->updateSprite(9,6);
          necrom->updateSprite(9,6); }

        if (walk->checkCollision(window))
        { wizard->updateSprite(6,2);
          paladin->updateSprite(6,2);
          necrom->updateSprite(6,2); }
    }
    wizard->animation(true);
    paladin->animation(true);
    necrom->animation(true);
} 

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::Yellow);

    wizard   ->draw(window);
    paladin  ->draw(window);
    necrom   ->draw(window);

    melee    ->draw(window);
    range    ->draw(window);
    die      ->draw(window);
    idle     ->draw(window);
    walk     ->draw(window);

    window   ->display();
}
