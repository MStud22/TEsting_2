//
// Created by Marco on 03/03/2023.
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

#ifndef TESTING_2_MENU_H
#define TESTING_2_MENU_H


class Menu {
public:

    Menu(sf::RenderWindow &window);
    void draw();

private:
    string Title = "Dungeon Adventure";
    string Start = "Start";

    sf::RenderWindow &window_;
};


#endif //TESTING_2_MENU_H
