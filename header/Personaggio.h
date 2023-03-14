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
    sf::RectangleShape bracciasx_;
    sf::RectangleShape bracciadx_;
    sf::RectangleShape gambasx_;
    sf::RectangleShape gambadx_;
    sf::CircleShape testa_;
    sf::RenderWindow &window_;
    float x_, y_;


    Personaggio(float x, float y, float size, RenderWindow &window);

    void disegna();


    void Steady_Animate();

    void Camminata_SX();

    void aggiornaPosizione();

    void Collision(string bordo);

    float getPositionx();

    float getPositiony();

    void setPosition(float x_, float y_);

    FloatRect getCollisionRect() const;

    string getCollisionDirection(const FloatRect &otherRect) const;

private:
    Texture texture;
    Sprite sprite;
    bool steady = true;
    bool camminata_dx = false;


    //variabile per animazione
    int swap_frame = 0;
    int swap_frame_camminata = 0;


};


#endif //TESTING_2_PERSONAGGIO_H
