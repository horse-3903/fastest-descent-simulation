#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>
#include <cmath>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// INFO CONSTANTS
const int INFO_WINDOW_WIDTH = 350;
const int INFO_WINDOW_HEIGHT = 200;

const int TEXT_FONT_SIZE = 20;
const int TEXT_MARGIN = 20;

// SIMULATION CONSTANTS
const double PI = 3.1415926535897932384643383279503;

const int SIM_WINDOW_WIDTH = 1000;
const int SIM_WINDOW_HEIGHT = 800;

const int WINDOW_WIDTH_CENTER = floor(SIM_WINDOW_WIDTH / 2);
const int WINDOW_HEIGHT_CENTER = floor(SIM_WINDOW_HEIGHT / 2);

const float BALL_RADIUS = 15.f;

const float RAMP_ANGLE = PI / 6; // 30 degrees
const float RAMP_LENGTH = 1000.f;
const float RAMP_THICKNESS = 5.f;

const float GRAV_ACCEL = 9.81f * 15.f; // Scaled gravity

// Ramp start position
const sf::Vector2f RAMP_START_POS(
    WINDOW_WIDTH_CENTER - (RAMP_LENGTH / 2) * cos(RAMP_ANGLE),
    WINDOW_HEIGHT_CENTER - (RAMP_LENGTH / 2) * sin(RAMP_ANGLE)
);

// Ramp end position
const sf::Vector2f RAMP_END_POS(
    RAMP_START_POS.x + RAMP_LENGTH * cos(RAMP_ANGLE),
    RAMP_START_POS.y + RAMP_LENGTH * sin(RAMP_ANGLE)
);

// Ball starting position
const sf::Vector2f BALL_START_POS(
    RAMP_START_POS.x - BALL_RADIUS,
    RAMP_START_POS.y - 2 * BALL_RADIUS
);

#endif