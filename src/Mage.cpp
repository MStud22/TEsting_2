//
// Created by Marco on 04/09/2023.
//

#include <iostream>
#include "../header/Mage.h"

Mage::Mage(float x, float y, float size, RenderWindow &window) : Personaggio(x, y, size, window) {

}

void Mage::Camminata_SX() {
    cout << "animazione da derivata" << endl;

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
        swap_frame_camminata = 4;       //PERMETTE IN LOOP DELLA CAMMINATA A SX A DIFFERENZA DI ALTRE CLASSI
    }
}

void Mage::Camminata_DX() {
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
        swap_frame_camminata = 3;
    }
}