//
// Created by Marco on 23/02/2023.
//
#include <iostream>
#include "../header/Personaggio.h"

Personaggio::Personaggio(float x, float y, float size, RenderWindow &window) :
        x_(x), y_(y), size_(size), window_(window)
{
    //colore rappresentativo personaggio
    sf::Color color_personaggio(sf::Color::Black);
    // Imposta i colori dei componenti dello stickman
    corpo_.setFillColor(color_personaggio);
    bracciadx_.setFillColor(color_personaggio);
    bracciasx_.setFillColor(color_personaggio);
    gambadx_.setFillColor(color_personaggio);
    gambasx_.setFillColor(color_personaggio);
    testa_.setFillColor(color_personaggio);

    // Imposta le dimensioni dei componenti dello stickman
    corpo_.setSize(sf::Vector2f(size_ / 2, size_));
    bracciadx_.setSize(sf::Vector2f(size_ * 0.7, size_ / 5));
    bracciasx_.setSize(sf::Vector2f(size_ * 0.7, size_ / 5));
    gambadx_.setSize(sf::Vector2f(size_ / 5, size_ * 1.25));
    gambasx_.setSize(sf::Vector2f(size_ / 5, size_ * 1.25));

    // Imposta le dimensioni e il colore della testa
    testa_.setRadius(size_ / 4.5);






    setPosition(x_, y_);


}

void Personaggio::disegna() {

    //todo CAPIRE3 LA DIFFERENZA TRA FRAME E FIXX

    aggiornaPosizione();
    sprite.setPosition(x_ - 40, y_ - 55); //aggiusta la immagine per entrare nei limiti personaggio
    //aggioramenti animazioni
    if (steady) {
        if (Engine::getElapsedFrames() % 30 == 0) {

            Steady_Animate();
        }
    }
    if (moving == "dx") {
        if (Engine::getElapsedFrames() % 6 == 0) {
            Camminata_DX();
        }
    }
    if (moving == "sx") {
        if (Engine::getElapsedFrames() % 6 == 0) {
            Camminata_SX();
        }
    }
    if (moving == "up") {
        if (Engine::getElapsedFrames() % 12 == 0) {
            Camminata_UP();
        }
    }
    if (moving == "down") {
        if (Engine::getElapsedFrames() % 10 == 0) {
            Camminata_DOWN();
        }
    }


    window_.draw(sprite);


}


void Personaggio::aggiornaPosizione() {

    steady = false;
    key_pressed = false;
    //todo fix if per evitare interruzioni nell'animazione
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Personaggio::collisione != "left") {
        x_ -= size_ / 10.0f;
        steady = false;
        moving = "sx";
        key_pressed = true;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Personaggio::collisione != "right") {
        x_ += size_ / 10.0f;
        moving = "dx";
        steady = false;
        key_pressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Personaggio::collisione != "top") {
        y_ -= size_ / 10.0f;
        steady = false;
        moving = "up";
        key_pressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Personaggio::collisione != "bottom") {
        y_ += size_ / 10.0f;
        steady = false;
        moving = "down";
        key_pressed = true;
    } else if (!key_pressed) {
        steady = true;
        moving = "";
        swap_frame_camminata = 0;
    }
    cout << key_pressed << endl;
    cout << moving << endl;

    Personaggio::collisione = "";
    // Aggiorna la posizione dei componenti del personaggio
    setPosition(x_, y_);

}


void Personaggio::setPosition(float x ,float y) {
    corpo_.setPosition(x, y - size_);
    bracciadx_.setPosition(corpo_.getPosition().x + (corpo_.getSize().x), corpo_.getPosition().y);
    bracciasx_.setPosition(corpo_.getPosition().x - (bracciasx_.getSize().x), corpo_.getPosition().y);
    gambasx_.setPosition(corpo_.getPosition().x, y);
    gambadx_.setPosition(corpo_.getPosition().x + ((corpo_.getSize().x / 7) * 4) + 1, y);
    testa_.setPosition(corpo_.getPosition().x, corpo_.getPosition().y - testa_.getRadius() * 2);
    x_ = x;
    y_ = y;
}


sf::FloatRect Personaggio::getCollisionRect() const {
    // Calcola la posizione e le dimensioni del rettangolo di collisione del personaggio
    float left = corpo_.getPosition().x;
    float top = corpo_.getPosition().y - corpo_.getSize().y;
    float right = corpo_.getPosition().x + corpo_.getSize().x;
    float bottom = corpo_.getPosition().y;

    left = std::min(left, bracciasx_.getPosition().x - bracciasx_.getSize().x / 3);
    top = std::min(top, std::min(bracciadx_.getPosition().y, bracciasx_.getPosition().y));
    right = std::max(right, std::max(bracciadx_.getPosition().x + bracciadx_.getSize().x,
                                     bracciasx_.getPosition().x + bracciasx_.getSize().x / 3));
    bottom = std::max(bottom, std::max(bracciadx_.getPosition().y + bracciadx_.getSize().y,
                                       bracciasx_.getPosition().y + bracciasx_.getSize().y));

    left = std::min(left, gambasx_.getPosition().x);
    top = std::min(top, gambasx_.getPosition().y);
    right = std::max(right, gambasx_.getPosition().x + gambasx_.getSize().x);
    bottom = std::max(bottom, gambasx_.getPosition().y + gambasx_.getSize().y);

    left = std::min(left, gambadx_.getPosition().x);
    top = std::min(top, gambadx_.getPosition().y);
    right = std::max(right, gambadx_.getPosition().x + gambadx_.getSize().x);
    bottom = std::max(bottom, gambadx_.getPosition().y + gambadx_.getSize().y);

    left = std::min(left, testa_.getPosition().x - testa_.getRadius());
    top = std::min(top, testa_.getPosition().y - testa_.getRadius());
    right = std::max(right, testa_.getPosition().x + testa_.getRadius());
    bottom = std::max(bottom, testa_.getPosition().y + testa_.getRadius());

    return sf::FloatRect(left, top, right - left, bottom - top);
}

// Funzione per determinare la direzione della collisione con un altro oggetto
std::string Personaggio::getCollisionDirection(const sf::FloatRect &rect) const {
    // Controlla la posizione reciproca dei due rettangoli
    float dx = (getCollisionRect().left + getCollisionRect().width / 2) - (rect.left + rect.width / 2);
    float dy = (getCollisionRect().top + getCollisionRect().height / 2) - (rect.top + rect.height / 2);
    float intersectX = std::abs(dx) - (getCollisionRect().width + rect.width) / 2;
    float intersectY = std::abs(dy) - (getCollisionRect().height + rect.height) / 2;

    // Se i rettangoli si intersecano, determina la direzione della collisione
    if (intersectX <= 0 && intersectY <= 0) {
        if (intersectX > intersectY) {
            return dx > 0 ? "left" : "right";
        } else {
            return dy > 0 ? "top" : "bottom";
        }
    } else {
        return "";
    }
}


void Personaggio::Collision(string bordo) {
    if (bordo == "top") {
        Personaggio::collisione = "top";
    }
    if (bordo == "left") {
        Personaggio::collisione = "left";
    }
    if (bordo == "bottom") {
        Personaggio::collisione = "bottom";
    }
    if (bordo == "right") {
        Personaggio::collisione = "right";
    }

}

void Personaggio::Steady_Animate() {

    if (swap_frame == 0) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/steady_animation/" + classe_ + ".png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame = 1;
    } else if (swap_frame == 1) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/steady_animation/" + classe_ + "2.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame = 0;

    }
    cout << "animating steady" << endl;
}

void Personaggio::Camminata_DX() {
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
        swap_frame_camminata = 1;
    }
}


void Personaggio::Camminata_SX() {
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
        swap_frame_camminata = 0;
    }
}

void Personaggio::Camminata_UP() {
    //TODO rimuovi i primi due frame del personaggio per non farlo girare mentre cammina

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
        swap_frame_camminata = 7;
    } else if (swap_frame_camminata == 7) {
        texture.loadFromFile("../assets/" + classe_ + "_animation/animazione_camminata_up/" + classe_ + "UP-8.png");
        sprite.setTexture(texture);
        sprite.setScale(2.7, 3);
        swap_frame_camminata = 0;
    }
}

void Personaggio::Camminata_DOWN() {
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
        swap_frame_camminata = 0;
    }
}

void Personaggio::setClasse(const string &classe) {
    classe_ = classe;
}

//todo rimuovi test

void Personaggio::setTexture(string classe_) {
    //imposta sprite immaggine
    texture.loadFromFile("../assets/" + classe_ + ".png");
    sprite.setTexture(texture);
    sprite.setScale(2.7, 3);

}

