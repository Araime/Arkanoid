#include<SFML/Graphics.hpp>
#include <time.h>
#include "GameSettings.h"

void HandleWindowEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}

int main()
{
    // init randomizer with random seed
    srand(static_cast<int>(time(nullptr)));

    // init game window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), GAME_NAME);
    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        HandleWindowEvents(window);
    }

    return 0;
}