#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const float PI = 3.14159265359f;

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

const int WINDOW_WIDTH_CENTER = floor(WINDOW_WIDTH / 2);
const int WINDOW_HEIGHT_CENTER = floor(WINDOW_HEIGHT / 2);

const float BALL_RADIUS = 15.0f;

const float RAMP_ANGLE = 30.0f;
const float RAMP_WIDTH = 1000.f;
const float RAMP_THICKNESS = 5.f;

float deg_to_rad(float deg) { return deg * (PI / 180); }

const sf::Vector2f RAMP_POSITION(
    WINDOW_WIDTH_CENTER - (RAMP_WIDTH / 2) * cos(deg_to_rad(RAMP_ANGLE)),
    WINDOW_HEIGHT_CENTER - (RAMP_WIDTH / 2) * sin(deg_to_rad(RAMP_ANGLE))
);

const sf::Vector2f BALL_STARTING_POSITION(
    RAMP_POSITION.x - BALL_RADIUS,
    RAMP_POSITION.y - 2 * BALL_RADIUS
);

class Ball {
  public:
    const float radius;
    const sf::Vector2f starting_position;

    Ball(float radius, sf::Vector2f starting_position)
        : radius(radius), starting_position(starting_position) {}

  private:
};

class Ramp {
  public:
    const bool line;
    const float ramp_angle;
    const float ramp_width;
    const float ramp_thickness;
    const int num_vertex;

    Ramp(bool line, float ramp_angle, float ramp_width, float ramp_thickness, int num_vertex): 
        line(line), 
        ramp_angle(ramp_angle), 
        ramp_width(ramp_width),
        ramp_thickness(ramp_thickness), 
        num_vertex(num_vertex)
    {
        this->init_shape();
    }

  private:
    void init_shape() {
        if (line) {
            sf::RectangleShape ramp(sf::Vector2f(RAMP_WIDTH, RAMP_THICKNESS));
            ramp.setPosition(RAMP_POSITION);
            ramp.setRotation(RAMP_ANGLE);
        } else {
            sf::VertexArray ramp;
            sf::Vertex starting_vertex(RAMP_POSITION, sf::Color::White);
            ramp.append(starting_vertex);
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fastest Descent Simulation");
    sf::RectangleShape ramp(sf::Vector2f(RAMP_WIDTH, RAMP_THICKNESS));
    ramp.setPosition(RAMP_POSITION);
    ramp.setRotation(RAMP_ANGLE);

    sf::CircleShape ball(BALL_RADIUS);
    ball.setPosition(BALL_STARTING_POSITION);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(ramp);
        window.draw(ball);
        window.display();
    }

    return 0;
}