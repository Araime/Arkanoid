#include "Paddle.h"

Paddle::Paddle(sf::Vector2f Position)
	: mSpeed(200.f),
	mShape(),
	mPosition(Position),
	mSize(100.f, 20.f)
{
	mShape.setSize(mSize);
	mShape.setFillColor(sf::Color::Green);
	mShape.setPosition(mPosition);
}
