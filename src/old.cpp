#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "collision.h"
#include "constants.h"
#include "util.h"

float ballVX = 0.f;
float ballVY = 0.f;

int main() {
    std::ios::sync_with_stdio(false);

    sf::RenderWindow sim_window(sf::VideoMode(SIM_WINDOW_WIDTH, SIM_WINDOW_HEIGHT), "Fastest Descent Simulation");
    InfoManager iman(sf::Vector2i(10, 10), "Data Values");

    sf::RectangleShape startRect(sf::Vector2f(2.f, SIM_WINDOW_HEIGHT));
    startRect.setPosition(sf::Vector2f(RAMP_START_POS.x, 0));
    startRect.setFillColor(sf::Color::Green);

    sf::RectangleShape endRect(sf::Vector2f(2.f, SIM_WINDOW_HEIGHT));
    endRect.setPosition(sf::Vector2f(RAMP_END_POS.x, 0));
    endRect.setFillColor(sf::Color::Red);

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

    // Create and position labels for the info window
    int globalTimeLabel = iman.AddInfo("Global Time : ");
    int ballTimeLabel = iman.AddInfo("Ball Time : ");
    int vxLabel = iman.AddInfo("Velocity-X : ");
    int vyLabel = iman.AddInfo("Velocity-Y : ");

    // Use pointers to sf::Drawable objects
    std::vector<sf::Drawable*> simSprites = {&ramp, &ball, &startRect, &endRect};

    sf::Clock clock;
    float globalTime = 0.f;
    float ballTime = 0.f;

    bool ballMotion = true;

    while (sim_window.isOpen() && iman.window.isOpen()) {
        sf::Event event;
        while (sim_window.pollEvent(event) || iman.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                sim_window.close();
                iman.window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        globalTime += deltaTime;
        
        if (ball.getPosition().x + BALL_RADIUS >= RAMP_START_POS.x && ball.getPosition().x + BALL_RADIUS <= RAMP_END_POS.x) {
            ballMotion = true;
            ballTime += deltaTime;
        } else {
            ballMotion = false;
        }

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

        iman.UpdateInfo(globalTimeLabel, "Global Time : " + std::to_string(globalTime));
        iman.UpdateInfo(ballTimeLabel, "Ball Motion Time : " + std::to_string(ballTime));
        iman.UpdateInfo(vxLabel, "Velocity-X : " + std::to_string(ballVX));
        iman.UpdateInfo(vyLabel, "Velocity-Y : " + std::to_string(ballVY));

        // Move the ball using the calculated velocity
        ball.move(ballVX * deltaTime, ballVY * deltaTime);

        // Clear and draw the simulation window
        sim_window.clear();
        for (auto sprite : simSprites) {
            sim_window.draw(*sprite);
        }
        sim_window.display();

        // Clear and draw the info window
        iman.DrawInfo();
    }

    return 0;
}