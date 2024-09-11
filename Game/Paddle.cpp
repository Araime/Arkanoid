#include "Paddle.h"
#include "GameSettings.h"
#include "Core.h"

Paddle::Paddle(sf::Vector2f Position)
	: mSpeed(300.f),
	mShape(),
	mPosition(Position),
	mSize(100.f, 20.f)
{
	mShape.setSize(mSize);
	mShape.setFillColor(sf::Color::Green);
	mShape.setOrigin(mSize.x / 2, mSize.y / 2);
	mShape.setPosition(mPosition);
}

void Paddle::Tick(float deltaTime)
{
	HandleInput(deltaTime);
}

void Paddle::HandleInput(float deltaTime)
{
	sf::Vector2f newPosition;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		newPosition = {mPosition.x -= mSpeed * deltaTime, mPosition.y};
		ClampPositionOnEdge(newPosition);
		SetPaddlePosition(newPosition);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		newPosition = {mPosition.x += mSpeed * deltaTime, mPosition.y};
		ClampPositionOnEdge(newPosition);
		SetPaddlePosition(newPosition);
	}
}

void Paddle::ClampPositionOnEdge(sf::Vector2f& Position)
{
	if (Position.x - mSize.x / 2 < 0.f)
	{
		mPosition.x = Position.x = mSize.x / 2;
	}

	if (Position.x + mSize.x / 2 > static_cast<float>(SCREEN_WIDTH))
	{
		mPosition.x = Position.x = static_cast<float>(SCREEN_WIDTH) - mSize.x / 2;
	}
}

void Paddle::SetPaddlePosition(sf::Vector2f& newPosition)
{
	mPosition = newPosition;
	mShape.setPosition(mPosition);
	LOG("Position x: %f", mPosition.x);
}
