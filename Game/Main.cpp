#include<SFML/Graphics.hpp>
#include <time.h>
#include "GameSettings.h"
#include "Game.h"
#include "Core.h"

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

	// init game object
	Game mGame;

	// init game timer
	sf::Clock gameTimer;
	float elapsedTime = gameTimer.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		LOG("ElapsedTime: %f", elapsedTime);

		// calculate the deltaTime
		const float currentTime = gameTimer.getElapsedTime().asSeconds();
		const float deltaTime = currentTime - elapsedTime;
		elapsedTime = currentTime;

		HandleWindowEvents(window);

		mGame.UpdateGame();
		mGame.DrawGame(window);

		LOG("CurrentTime: %f", currentTime);
		LOG("DeltaTime: %f", deltaTime);
	}

	return 0;
}