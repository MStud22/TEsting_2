//
// Created by Marco on 20/09/2023.
//
#include <SFML/Graphics.hpp>
#include <string>
#include "Personaggio.h"

#ifndef TESTING_2_FIGHTING_WINDOW_H
#define TESTING_2_FIGHTING_WINDOW_H

using namespace std;

class Fighting_Window {
public:
    void draw();

    Fighting_Window(sf::RenderWindow &window);

private :
    sf::RenderWindow &window;

    sf::RectangleShape backgroundRect;
    sf::RectangleShape Fight_Rect1;
    sf::RectangleShape Fight_Rect2;
    sf::Text fightText;
    sf::Text runText;
    sf::Text talkText;
    sf::Text itemsText;


    sf::Font fontText;

    Personaggio *p;

};


#endif //TESTING_2_FIGHTING_WINDOW_H
