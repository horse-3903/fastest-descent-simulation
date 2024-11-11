#include <iostream>

#include <cmath>
#include <SFML/Graphics.hpp>

#include "collision.h"
#include "constants.h"

float ballVX = 0.f;
float ballVY = 0.f;

int main() {
    std::ios::sync_with_stdio(false);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fastest Descent Simulation");

    // Creating a vertex array for the ramp using TriangleStrip
    sf::VertexArray ramp(sf::TriangleStrip, 4);

    // Define the four corners of the ramp as a TriangleStrip
    ramp[0].position = sf::Vector2f(RAMP_START_POS.x, RAMP_START_POS.y);
    ramp[1].position = sf::Vector2f(RAMP_START_POS.x, RAMP_START_POS.y + RAMP_THICKNESS);
    ramp[2].position = sf::Vector2f(RAMP_END_POS.x, RAMP_END_POS.y);
    ramp[3].position = sf::Vector2f(RAMP_END_POS.x, RAMP_END_POS.y + RAMP_THICKNESS);

    sf::CircleShape ball(BALL_RADIUS);
    ball.setPosition(BALL_START_POS);
    ball.setFillColor(sf::Color::Red);

    // Load font
    sf::Font font;
    if (!font.loadFromFile("C:\\SFML\\arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1; // Exit if font loading fails
    }

    sf::Text globalTimeLabel;
    globalTimeLabel.setFont(font);
    globalTimeLabel.setCharacterSize(18);
    globalTimeLabel.setString("Global Time : ");
    globalTimeLabel.setPosition(sf::Vector2f(10, 10));
    globalTimeLabel.setFillColor(sf::Color::White);

    sf::Text vxLabel;
    vxLabel.setFont(font);
    vxLabel.setCharacterSize(18);
    vxLabel.setString("Velocity-X : ");
    vxLabel.setPosition(sf::Vector2f(10, 40));
    vxLabel.setFillColor(sf::Color::White);
    
    sf::Text vyLabel;
    vyLabel.setFont(font);
    vyLabel.setCharacterSize(18);
    vyLabel.setString("Velocity-Y : ");
    vyLabel.setPosition(sf::Vector2f(10, 70));
    vyLabel.setFillColor(sf::Color::White);

    // Use pointers to sf::Drawable objects
    std::vector<sf::Drawable*> spriteArr = {&ramp, &ball, &globalTimeLabel, &vxLabel, &vyLabel};

    sf::Clock clock;
    float globalTime = 0.f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        globalTime += deltaTime;

        if (rampCollision(ball.getPosition(), BALL_RADIUS, RAMP_START_POS, RAMP_END_POS)) {
            if (ballVX == 0) 
                ballVY = 0;
            
            // Apply acceleration along the ramp
            ballVX += sin(RAMP_ANGLE) * GRAV_ACCEL * cos(RAMP_ANGLE) * deltaTime;
            ballVY += sin(RAMP_ANGLE) * GRAV_ACCEL * sin(RAMP_ANGLE) * deltaTime;
        } else {
            // Apply gravity vertically if not on the ramp
            ballVY += GRAV_ACCEL * deltaTime;
        }

        globalTimeLabel.setString("Global Time : " + std::to_string(globalTime));
        vxLabel.setString("Velocity-X : " + std::to_string(ballVX));
        vyLabel.setString("Velocity-Y : " + std::to_string(ballVY));

        // Move the ball using the calculated Vocity
        ball.move(ballVX * deltaTime, ballVY * deltaTime);

        window.clear();

        // Draw all the sprites
        for (auto sprite : spriteArr) {
            window.draw(*sprite);
        }

        window.display();
    }

    return 0;
}