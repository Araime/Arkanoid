#include "Game.h"

Game::Game()
{

}

void Game::ClearGame()
{
	delete mPaddle;
}

void Game::UpdateGame()
{

}

void Game::DrawGame(sf::RenderWindow& window)
{
	window.clear();

	window.draw(mPaddle->GetShape());

	window.display();
}
