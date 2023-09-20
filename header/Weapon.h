//
// Created by Marco on 05/09/2023.
//


#ifndef TESTING_2_WEAPON_H
#define TESTING_2_WEAPON_H

#include "Engine.h"

class Weapon {


public:


    int strenght;
    string name;


    explicit Weapon(int strenght, string name);

    int getStrenght() const;

    void setStrenght(int strenght);

    const string &getName() const;

    void setName(const string &name);
};


#endif //TESTING_2_WEAPON_H
