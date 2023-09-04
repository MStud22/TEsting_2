//
// Created by Marco on 19/04/2023.
//

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

#ifndef TESTING_2_SCELTA_PERSONAGGIO_H
#define TESTING_2_SCELTA_PERSONAGGIO_H


class Scelta_personaggio {
public:

    Scelta_personaggio(sf::RenderWindow &window);

    void draw();

private:
    string Title = "CHOOSE YOUR HERO";
    string Knight = "The Mighty Knight";
    string Mage = "The Powerfull Mage";
    string Thief = "The Sneaky Thief";
    string Archer = "The Brave Archer";
    sf::RenderWindow &window_;
};


#endif //TESTING_2_SCELTA_PERSONAGGIO_H
