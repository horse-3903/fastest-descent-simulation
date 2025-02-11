#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Ball {
public:
    Ball(float radius, sf::Vector2f position, sf::Color color);
    
    void applyAcceleration(float ax, float ay, float dt);
    void updatePosition(float dt);
    void updateVelocity(float dvx, float dvy);
    void draw(sf::RenderWindow& window);

    float radius;
    bool isMotion;
    float time;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Color color;
};

#endif