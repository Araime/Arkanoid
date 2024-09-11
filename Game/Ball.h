#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f Position);
	void Tick(float deltaTime);
	float GetSpeed() const { return mSpeed; }
	sf::Vector2f GetPosition() const { return mPosition; }
	void SetPosition(sf::Vector2f Position) { mPosition = Position; }
	sf::CircleShape GetShape() const { return mShape; }

private:
	float mSpeed;
	float mRadius;
	sf::CircleShape mShape;
	sf::Vector2f mPosition;
};

