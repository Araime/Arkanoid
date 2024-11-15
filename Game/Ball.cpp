#include "Ball.h"
#include "Core.h"
#include "Paddle.h"
#include "GameSettings.h"

Ball::Ball(sf::Vector2f Position)
	: mSpeed(150.f),
	mRadius(20.f),
	mShape(),
	mPosition(Position),
	mFlyingUp(true),
	mFlyingRight(true)
{
	mShape.setRadius(mRadius);
	mShape.setFillColor(sf::Color::Blue);
	mShape.setPosition(mPosition);
	mShape.setOrigin(mRadius, mRadius);
}

void Ball::Tick(float deltaTime)
{
	Update(deltaTime);
}

void Ball::CheckCollisionWithPaddle(Paddle* Paddle)
{
	sf::FloatRect ObjectBounds = Paddle->GetShape().getGlobalBounds();

	if (ObjectBounds.intersects(mShape.getGlobalBounds()))
	{
		LOG("Collide!!!");
	}
}

void Ball::Update(float deltaTime)
{
	sf::Vector2f newPosition{mPosition.x, mPosition.y};

	// Check if the ball is flying up
	if (mFlyingUp)
	{
		newPosition = {mPosition.x, mPosition.y -= mSpeed * deltaTime};
	}
	else if (!mFlyingUp)
	{
		newPosition = {mPosition.x, mPosition.y += mSpeed * deltaTime};
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

	ClampPositionOnEdge(newPosition);
	UpdateBallPosition(newPosition);
}

void Ball::ClampPositionOnEdge(sf::Vector2f& Position)
{
	// Check the collision of the ball at the x coordinate
	if (mPosition.x + mRadius > SCREEN_WIDTH)
	{
		mFlyingRight = false;
		LOG("Ball x position is: %f, y position is: %f", GetPosition().x, GetPosition().y);
	}
	else if (mPosition.x - mRadius <= 0)
	{
		mFlyingRight = true;
		LOG("Ball x position is: %f, y position is: %f", GetPosition().x, GetPosition().y);
	}

	// Check the collision of the ball at the y coordinate
	if (mPosition.y - mRadius <= 0)
	{
		mFlyingUp = false;
		LOG("Ball x position is: %f, y position is: %f", GetPosition().x, GetPosition().y);
	}
	else if (mPosition.y + mRadius >= SCREEN_HEIGHT)
	{
		mFlyingUp = true;
		LOG("Ball x position is: %f, y position is: %f", GetPosition().x, GetPosition().y);
	}
}

void Ball::UpdateBallPosition(sf::Vector2f& Position)
{
	mPosition = Position;
	mShape.setPosition(mPosition);
}
