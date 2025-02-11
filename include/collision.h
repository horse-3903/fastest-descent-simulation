#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

// Function to check if the ball is colliding with the ramp
bool rampCollision(const sf::Vector2f &circlePos, float radius, const sf::Vector2f &pointA, const sf::Vector2f &pointB);

#endif
