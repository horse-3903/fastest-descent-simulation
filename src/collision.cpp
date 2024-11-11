#include "collision.h"

bool rampCollision(const sf::Vector2f &circlePos, float radius, const sf::Vector2f &pointA, const sf::Vector2f &pointB) {
	const sf::Vector2f circleCenter = circlePos + sf::Vector2f(radius, radius);

    // Vector from pointA to circleCenter
    sf::Vector2f ac = circleCenter - pointA;
    // Vector from pointA to pointB
    sf::Vector2f ab = pointB - pointA;

    // Project ac onto ab, but we only want the distance from pointA to the projection
    float abLengthSquared = ab.x * ab.x + ab.y * ab.y;
    float acDotAb = ac.x * ab.x + ac.y * ab.y;
    float t = acDotAb / abLengthSquared;

    // Clamp t to be between 0 and 1 to ensure the closest point is within the segment
    // t = std::max(0.f, std::min(1.f, t));

    // Find the closest point on the line segment
    sf::Vector2f closestPoint = pointA + t * ab;

    // Vector from circle center to closest point
    sf::Vector2f circleToClosest = closestPoint - circleCenter;

    // Check if the distance from the circle center to the closest point is less than the radius
    float distanceSquared = circleToClosest.x * circleToClosest.x + circleToClosest.y * circleToClosest.y;

    return distanceSquared <= radius * radius;
}
