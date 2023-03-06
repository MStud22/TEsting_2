//
// Created by Marco on 03/03/2023.
#include <SFML/Graphics.hpp>
#include <string>

#ifndef TESTING_2_MENU_H
#define TESTING_2_MENU_H


class Menu {
public:

    Menu(sf::RenderWindow &window);

    void draw(const std::vector<std::string> &menu_items);

private:
    sf::RenderWindow &window_;
};


#endif //TESTING_2_MENU_H
