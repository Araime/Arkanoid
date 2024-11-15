#pragma once

#include <SFML/Graphics.hpp>

class Paddle;

class Ball
{
public:
	Ball(sf::Vector2f Position);
	void Tick(float deltaTime);
	float GetSpeed() const { return mSpeed; }
	sf::Vector2f GetPosition() const { return mPosition; }
	void SetPosition(sf::Vector2f Position) { mPosition = Position; }
	sf::CircleShape GetShape() const { return mShape; }
	void CheckCollisionWithPaddle(Paddle* Paddle);

private:
	void Update(float deltaTime);
	void ClampPositionOnEdge(sf::Vector2f& Position);
	void UpdateBallPosition(sf::Vector2f& Position);

	float mSpeed;
	float mRadius;
	bool mFlyingUp;
	bool mFlyingRight;
	sf::CircleShape mShape;
	sf::Vector2f mPosition;
};

