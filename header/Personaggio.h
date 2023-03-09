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

    int Frame_counter();

    void Steady_Animate();

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

    //variabili per il caount dei frame
    clock_t last_time;
    int fps;
    int frame_count = 0;

    //variabile per animazione
    int swap_frame = 0;


};


#endif //TESTING_2_PERSONAGGIO_H
