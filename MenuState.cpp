#include "MenuState.h"
#include "Game.h"
#include "Gameplay.h"

MenuState::MenuState(Game* game):
GameState(game)
{
    t_splash.loadFromFile("splash.jpg");
    s_splash.setTexture(t_splash);
}

MenuState::~MenuState()
{

}

void MenuState::update(sf::RenderWindow* window)

{
        // events  
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                game->setState(new Gameplay(game));
            }
            
        }

        // keyboard
        
        // mouse
}

void MenuState::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(s_splash);
    window->display();
}
