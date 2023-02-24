//
// Created by Marco on 23/02/2023.
//

#ifndef TESTING_2_PERSONAGGIO_H
#define TESTING_2_PERSONAGGIO_H
#include "Engine.h"

class Personaggio {
public:
    float size_;
    sf::RectangleShape corpo_;
    string collisione;
    sf::RectangleShape braccia_;
    sf::RectangleShape gambasx_;
    sf::RectangleShape gambadx_;
    sf::CircleShape testa_;
    sf::RenderWindow& window_;

    Personaggio(float x, float y, float size, RenderWindow &window);

    void disegna() ;

    void aggiornaPosizione();
    void Collision(string bordo);
    float getPositionx();

    float getPositiony();

    void setPosition(float x_,float  y_);

    FloatRect getCollisionRect() const;

private:
    float x_, y_ ;




};


#endif //TESTING_2_PERSONAGGIO_H
