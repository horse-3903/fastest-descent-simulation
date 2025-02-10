#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "util.h"
#include "constants.h"

int main(){
    std::ios::sync_with_stdio(false);

    InfoManager man(sf::Vector2i(10, 10), "Data Values");

    int test_idx = man.AddInfo("test : ");
    int noob_idx = man.AddInfo("haha noob : ");

    sf::Clock clock;

    while (man.window.isOpen()){
        sf::Event event;
        while (man.window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                man.window.close();
                std::cout << "closed?" << std::endl;
            }
        }

        float time = clock.getElapsedTime().asSeconds();

        man.UpdateInfo(test_idx, "test : " + std::to_string(time));
        man.UpdateInfo(noob_idx, "noob : " + std::to_string(time * 2));
        man.DrawInfo();
    }

    return 0;
}