#pragma once

#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(sf::Vector2f Position);
	float GetSpeed() const { return mSpeed; }
	sf::Vector2f GetPosition() const { return mPosition; }
	void SetPosition(sf::Vector2f Position) { mPosition = Position; }
	sf::RectangleShape GetShape() const { return mShape; }

private:
	float mSpeed;
	sf::RectangleShape mShape;
	sf::Vector2f mPosition;
	sf::Vector2f mSize;

};

