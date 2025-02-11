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

    int addInfo(std::string label);
    void updateInfo(int idx, std::string label);
    void updateSize(int width, int height);
    void drawInfo();

private:
    sf::Font font;
    sf::Vector2i position;
    std::string title;
    std::vector<sf::Text> labels;

    int maxWidth;
    int prevMaxWidth;

    std::pair<int, int> calculateSize();
};

#endif
