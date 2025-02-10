#include "collision.h"

bool rampCollision(const sf::Vector2f &circlePos, float radius, const sf::Vector2f &pointA, const sf::Vector2f &pointB) {
	const sf::Vector2f circleCenter = circlePos + sf::Vector2f(radius, radius);

    sf::Vector2f ac = circleCenter - pointA;
    sf::Vector2f ab = pointB - pointA;

    float abLengthSquared = ab.x * ab.x + ab.y * ab.y;
    float acDotAb = ac.x * ab.x + ac.y * ab.y;
    float t = acDotAb / abLengthSquared;

    t = std::max(0.f, std::min(1.f, t));

    sf::Vector2f closestPoint = pointA + t * ab;

    sf::Vector2f circleToClosest = closestPoint - circleCenter;

    float distanceSquared = circleToClosest.x * circleToClosest.x + circleToClosest.y * circleToClosest.y;

    return distanceSquared <= radius * radius;
}
