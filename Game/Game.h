#pragma once

#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"

class Game
{
public:
	Game();
	void ClearGame();
	void UpdateGame(float deltaTime);
	void DrawGame(sf::RenderWindow& window);

	Paddle* mPaddle = new Paddle({400.f, 700.f});
	Ball* mBall = new Ball({450.f, 600.f});
};
