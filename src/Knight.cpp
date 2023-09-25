//
// Created by Marco on 04/09/2023.
//

#include "../header/Knight.h"

Knight::Knight(float x, float y, float size, RenderWindow &window, Weapon *weapon) : Personaggio(x, y, size, window,
                                                                                                 weapon),
                                                                                     weapon(*weapon) {

}


const Weapon &Knight::getWeapon() const {
    return weapon;
}

void Knight::setWeapon(const Weapon &weapon) {
    Knight::weapon = weapon;
}




