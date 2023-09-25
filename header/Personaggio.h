//
// Created by Marco on 23/02/2023.
//

#ifndef TESTING_2_PERSONAGGIO_H
#define TESTING_2_PERSONAGGIO_H
#include "Engine.h"
#include "Weapon.h"

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
    string classe_;

    Weapon *weapon;


    Personaggio(float x, float y, float size, RenderWindow &window, Weapon *weapon);

    void disegna();


    void Steady_Animate();

    void virtual Camminata_DX();

    void virtual Camminata_SX();

    void virtual Camminata_UP();

    void virtual Camminata_DOWN();

    void aggiornaPosizione();

    void Collision(string bordo);

    float getPositionx();

    float getPositiony();

    void setPosition(float x_, float y_);

    FloatRect getCollisionRect() const;

    string getCollisionDirection(const FloatRect &otherRect) const;

    void setClasse(const string &classe);

    void setTexture(string classe_);

    Weapon *getWeapon() const;

    void setWeapon(Weapon *weapon);

    int getHp() const;

    void setHp(int hp);

    int getArmor() const;

    void setArmor(int armor);

protected:
    Texture texture;
    Sprite sprite;
    bool steady = true;
    string moving;


    //variabile movimento
    bool key_pressed;


    //variabile per animazione
    int swap_frame = 0;
    int swap_frame_camminata = 0;
private:
    int hp;
    int armor;


};


#endif //TESTING_2_PERSONAGGIO_H
