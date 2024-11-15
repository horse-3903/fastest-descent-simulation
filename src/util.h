#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class InfoManager {
public:
    InfoManager(sf::Vector2i position, std::string title);

    sf::RenderWindow window;

    int AddInfo(std::string label);
    void UpdateInfo(int idx, std::string label);
    void UpdateSize(int width, int height);
    void DrawInfo();

private:
    sf::Font font;
    sf::Vector2i position;
    std::string title;
    std::vector<sf::Text> labels;

    int maxWidth;
    int prevMaxWidth;

    std::pair<int, int> CalculateSize();
};

#endif
