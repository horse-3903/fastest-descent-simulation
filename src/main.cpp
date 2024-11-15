#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "util.h"
#include "constants.h"

int main(){
    std::ios::sync_with_stdio(false);

    InfoManager iman(sf::Vector2i(10, 10), "Data Values");

    int test_idx = iman.AddInfo("test : ");
    int noob_idx = iman.AddInfo("haha noob : ");

    sf::Clock clock;

    while (iman.window.isOpen()){
        sf::Event event;
        while (iman.window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                iman.window.close();
                std::cout << "closed?" << std::endl;
            }
        }

        float time = clock.getElapsedTime().asSeconds();

        iman.UpdateInfo(test_idx, "test : " + std::to_string(time));
        iman.UpdateInfo(noob_idx, "noob : " + std::to_string(time * 2));
        iman.DrawInfo();
    }

    return 0;
}