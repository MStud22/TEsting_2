//
// Created by Marco on 05/09/2023.
//

#ifndef TESTING_2_THIEF_H
#define TESTING_2_THIEF_H

#include "Personaggio.h"

class Thief : public Personaggio {

public :
    int hp;
    int armor;
    Weapon weapon;


    Thief(float x, float y, float size, RenderWindow &window, Weapon *weapon);

    void Camminata_DOWN() override;

    void Camminata_UP() override;

    void Camminata_DX() override;

    void Camminata_SX() override;
};


#endif //TESTING_2_THIEF_H
