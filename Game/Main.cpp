#include<SFML/Graphics.hpp>
#include <time.h>
#include "GameSettings.h"
#include "Game.h"

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
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);
	window.setFramerateLimit(FPS);
	window.setVerticalSyncEnabled(true);

	// init game object
	Game mGame;

	// init game timer
	sf::Clock gameTimer;
	float deltaTime = 0.f;

	while (window.isOpen())
	{
		// calculate the deltaTime
		const float deltaTime = gameTimer.restart().asSeconds();

		HandleWindowEvents(window);

		mGame.UpdateGame(deltaTime);
		mGame.DrawGame(window);
	}

	return 0;
}