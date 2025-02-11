#include "include/ball.h"
#include "include/constants.h"

Ball::Ball(float radius, sf::Vector2f position, sf::Color color)
    : radius(radius), position(position), color(color), vx(0.0f), vy(0.0f) {
    isMotion = true;
    time = 0.0f;
}

void Ball::applyAcceleration(float ax, float ay, float dt){
    vx += ax * dt;
    vy += ay * dt;
}

void Ball::updatePosition(float dt){
    position.x += vx * dt;
    position.y += vy * dt;
}

void Ball::updateVelocity(float dvx, float dvy){
    vx += dvx;
    vy += dvy;
}

void Ball::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(position);

    window.draw(circle);
}
