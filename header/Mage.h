//
// Created by Marco on 04/09/2023.
//

#ifndef TESTING_2_MAGE_H
#define TESTING_2_MAGE_H


#include "Personaggio.h"

class Mage : public Personaggio {

public :
    int hp;
    int armor;
    Weapon weapon;

    Mage(float x, float y, float size, RenderWindow &window, Weapon *weapon);

    void Camminata_SX() override;

    void Camminata_DX() override;

    void Camminata_UP() override;
};


#endif //TESTING_2_MAGE_H
