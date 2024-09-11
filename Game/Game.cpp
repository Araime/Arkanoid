#include "Game.h"

Game::Game()
{

}

void Game::ClearGame()
{
	delete mPaddle;
}

void Game::UpdateGame(float deltaTime)
{
	mPaddle->Tick(deltaTime);
}

void Game::DrawGame(sf::RenderWindow& window)
{
	window.clear();

	window.draw(mPaddle->GetShape());

	window.display();
}
