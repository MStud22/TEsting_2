//
// Created by Marco on 05/09/2023.
//

#include "../header/Thief.h"


Thief::Thief(float x, float y, float size, RenderWindow &window, Weapon *weapon) : Personaggio(x, y, size, window,
                                                                                               weapon),
                                                                                   weapon(*weapon) {


}

void Thief::Camminata_UP() {

    if (swap_frame_camminata == 0) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-1.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 1;
    } else if (swap_frame_camminata == 1) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-2.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 2;
    } else if (swap_frame_camminata == 2) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-3.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 3;
    } else if (swap_frame_camminata == 3) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-4.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 4;
    } else if (swap_frame_camminata == 4) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-5.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    } else if (swap_frame_camminata == 5) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-6.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 6;
    } else if (swap_frame_camminata == 6) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-7.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    }
}

void Thief::Camminata_DOWN() {
    if (swap_frame_camminata == 0) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-1.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 1;
    } else if (swap_frame_camminata == 1) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-2.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 2;
    } else if (swap_frame_camminata == 2) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-3.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 3;
    } else if (swap_frame_camminata == 3) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-4.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 4;
    } else if (swap_frame_camminata == 4) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-5.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    } else if (swap_frame_camminata == 5) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-6.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 6;
    } else if (swap_frame_camminata == 6) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_down/" + classe_ + "DOWN-7.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    }
}


void Thief::Camminata_DX() {
    if (swap_frame_camminata == 0) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-1.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 1;
    } else if (swap_frame_camminata == 1) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-2.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 2;
    } else if (swap_frame_camminata == 2) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-3.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 3;
    } else if (swap_frame_camminata == 3) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-4.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 4;
    } else if (swap_frame_camminata == 4) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-5.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    } else if (swap_frame_camminata == 5) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-6.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 6;
    } else if (swap_frame_camminata == 6) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatadx/" + classe_ + "DX-7.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    }
}

void Thief::Camminata_SX() {
    if (swap_frame_camminata == 0) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-1.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 1;
    } else if (swap_frame_camminata == 1) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-2.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 2;
    } else if (swap_frame_camminata == 2) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-3.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 3;
    } else if (swap_frame_camminata == 3) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-4.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 4;
    } else if (swap_frame_camminata == 4) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-5.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    } else if (swap_frame_camminata == 5) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-6.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 6;
    } else if (swap_frame_camminata == 6) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminatasx/" + classe_ + "SX-7.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 5;
    }
}