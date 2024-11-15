#include "Ball.h"
#include "Core.h"

Ball::Ball(sf::Vector2f Position)
	: mSpeed(300.f),
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
}

void Ball::ClampPositionOnEdge(sf::Vector2f& Position)
{

}

void Ball::UpdateBallPosition(sf::Vector2f& newPosition)
{

}
