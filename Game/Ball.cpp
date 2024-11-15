#include "Ball.h"
#include "Core.h"

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

void Ball::ClampPositionOnEdge(sf::Vector2f& Position)
{

}

void Ball::Update(float deltaTime)
{
	sf::Vector2f newPosition;

	if (mFlyingUp)
	{
		newPosition = {mPosition.x, mPosition.y -= mSpeed * deltaTime};
	}
	else
	{
		newPosition = {mPosition.x, mPosition.y += mSpeed * deltaTime};
	}

	if (mFlyingRight)
	{
		newPosition = {mPosition.x += mSpeed * deltaTime, mPosition.y};
	}
	else
	{
		newPosition = {mPosition.x -= mSpeed * deltaTime, mPosition.y};
	}

	UpdateBallPosition(newPosition);
}

void Ball::UpdateBallPosition(sf::Vector2f& Position)
{
	mPosition = Position;
	mShape.setPosition(mPosition);
}
