//
// Created by Marco on 05/09/2023.
//

#include "../header/Weapon.h"


Weapon::Weapon(int strenght, string name) : strenght(strenght), name(name) {}

int Weapon::getStrenght() const {
    return strenght;
}

void Weapon::setStrenght(int strenght) {
    Weapon::strenght = strenght;
}

const string &Weapon::getName() const {
    return name;
}

void Weapon::setName(const string &name) {
    Weapon::name = name;
}
