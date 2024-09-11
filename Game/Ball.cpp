#include "Ball.h"

Ball::Ball(sf::Vector2f Position)
	: mSpeed(300.f),
	mRadius(25.f),
	mShape(),
	mPosition(Position)
{
	mShape.setRadius(mRadius);
	mShape.setFillColor(sf::Color::Blue);
	mShape.setPosition(mPosition);
}

void Ball::Tick(float deltaTime)
{

}
