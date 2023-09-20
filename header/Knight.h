//
// Created by Marco on 04/09/2023.
//

#ifndef TESTING_2_KNIGHT_H
#define TESTING_2_KNIGHT_H

#include "Engine.h"
#include "Personaggio.h"
#include "Weapon.h"

class Knight : public Personaggio {

public :
    int hp;
    int armor;
    Weapon weapon;


    Knight(float x, float y, float size, RenderWindow &window, Weapon *weapon);

    int getHp() const;

    void setHp(int hp);

    int getArmor() const;

    void setArmor(int armor);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);
};


#endif //TESTING_2_KNIGHT_H
