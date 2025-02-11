#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "include/ball.h"
#include "include/collision.h"
#include "include/constants.h"
#include "include/util.h"

int main(){
    std::ios::sync_with_stdio(false);

    sf::Clock clock;
    float globalTime = 0.f;

    float balldVX;
    float balldVY;

    sf::RenderWindow sim_window(sf::VideoMode(SIM_WINDOW_WIDTH, SIM_WINDOW_HEIGHT), "Fastest Descent Simulation");
    InfoManager info_window(sf::Vector2i(10, 10), "Data Values");

    // Info Labels
    int globalTimeLabel = info_window.addInfo("Global Time : ");
    int ballTimeLabel = info_window.addInfo("Ball Time : ");
    int vxLabel = info_window.addInfo("Velocity-X : ");
    int vyLabel = info_window.addInfo("Velocity-Y : ");

    // Sprites
    Ball ball(BALL_RADIUS, BALL_START_POS, sf::Color::Red);

    while (sim_window.isOpen() && info_window.window.isOpen()){
        // Event Handling
        sf::Event event;
        while (sim_window.pollEvent(event) || info_window.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                sim_window.close();
                info_window.window.close();
            }
        }
        
        // Update Time
        float deltaTime = clock.getElapsedTime().asSeconds();
        globalTime += deltaTime;
        
        // Update Information Window
        info_window.updateInfo(globalTimeLabel, "Global Time : " + std::to_string(globalTime));
        info_window.updateInfo(ballTimeLabel, "Ball Motion Time : " + std::to_string(ball.time));
        info_window.updateInfo(vxLabel, "Velocity-X : " + std::to_string(ball.vx));
        info_window.updateInfo(vyLabel, "Velocity-Y : " + std::to_string(ball.vy));

        // Check for Ball Motion
        if (ball.position.x + BALL_RADIUS >= RAMP_START_POS.x && ball.position.x + BALL_RADIUS <= RAMP_END_POS.x) {
            ball.isMotion = true;
            ball.time += deltaTime;
        } else {
            ball.isMotion = false;
        }

        // Check for Ball Collision
        if (ball.isMotion && rampCollision(ball.position, BALL_RADIUS, RAMP_START_POS, RAMP_END_POS)) {
            if (balldVX == 0) 
                balldVY = 0;
            
            balldVX = sin(RAMP_ANGLE) * cos(RAMP_ANGLE) * (GRAV_ACCEL * deltaTime);
            balldVY = sin(RAMP_ANGLE) * sin(RAMP_ANGLE) * (GRAV_ACCEL * deltaTime);
        } else {
            balldVY += GRAV_ACCEL * deltaTime;
        }

        ball.updateVelocity(balldVX, balldVY);
        ball.updatePosition(deltaTime);

        // Clear Simulation Window
        sim_window.clear();

        // Draw Sprites
        ball.draw(sim_window);
        sim_window.display();

        info_window.drawInfo();
    }

    return 0;
}