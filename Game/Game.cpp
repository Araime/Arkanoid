#include "Game.h"

Game::Game()
{

}

void Game::ClearGame()
{
	delete mPaddle;
	delete mBall;
}

void Game::UpdateGame(float deltaTime)
{
	mPaddle->Tick(deltaTime);
	mBall->Tick(deltaTime);
	mBall->CheckCollisionWithPaddle(mPaddle);
}

void Game::DrawGame(sf::RenderWindow& window)
{
	window.clear();

	window.draw(mPaddle->GetShape());
	window.draw(mBall->GetShape());

	window.display();
}
