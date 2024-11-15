#include "Ball.h"
#include "Core.h"
#include "GameSettings.h"

Ball::Ball(sf::Vector2f Position)
	: mSpeed(250.f),
	mRadius(20.f),
	mShape(),
	mPosition(Position),
	mFlyingUp(true),
	mFlyingRight(true)
{
	mShape.setRadius(mRadius);
	mShape.setFillColor(sf::Color::Blue);
	mShape.setOrigin(mRadius, mRadius);
	mShape.setPosition(mPosition);
}

void Ball::Tick(float deltaTime)
{
	LOG("Ball x position is: %f, y position is: %f", GetPosition().x, GetPosition().y);

	Update(deltaTime);
}

void Ball::Update(float deltaTime)
{
	sf::Vector2f newPosition;

	// Check if the ball is flying up
	if (mFlyingUp)
	{
		newPosition = {mPosition.x, mPosition.y -= mSpeed * deltaTime};
	}
	else if (!mFlyingUp)
	{
		newPosition = {mPosition.x, mPosition.y += mSpeed * deltaTime};
	}
	else
	{
		newPosition = {mPosition.x, mPosition.y};
	}

	// Check if the ball is flying right
	if (mFlyingRight)
	{
		newPosition = {mPosition.x += mSpeed * deltaTime, mPosition.y};
	}
	else if (!mFlyingRight)
	{
		newPosition = {mPosition.x -= mSpeed * deltaTime, mPosition.y};
	}
	else
	{
		newPosition = {mPosition.x, mPosition.y};
	}

	ClampPositionOnEdge(newPosition);
	UpdateBallPosition(newPosition);
}

void Ball::ClampPositionOnEdge(sf::Vector2f& Position)
{
	// Check the collision of the ball at the x coordinate
	if (mPosition.x + mRadius >= SCREEN_WIDTH)
	{
		mFlyingRight = false;
	}
	else if (mPosition.x - mRadius <= 0)
	{
		mFlyingRight = true;
	}

	// Check the collision of the ball at the y coordinate
	if (mPosition.y - mRadius <= 0)
	{
		mFlyingUp = false;
	}
	else if (mPosition.y + mRadius >= SCREEN_HEIGHT)
	{
		mFlyingUp = true;
	}
}

void Ball::UpdateBallPosition(sf::Vector2f& Position)
{
	mPosition = Position;
	mShape.setPosition(mPosition);
}
