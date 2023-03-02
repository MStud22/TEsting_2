//
// Created by Marco on 23/02/2023.
//
#include <iostream>
#include "../header/Personaggio.h"

Personaggio::Personaggio(float x, float y, float size, RenderWindow& window) :
        x_(x), y_(y), size_(size), window_(window)
{


    // Imposta i colori dei componenti dello stickman
    corpo_.setFillColor(sf::Color::White);
    bracciadx_.setFillColor(sf::Color::White);
    bracciasx_.setFillColor(sf::Color::White);
    gambadx_.setFillColor(sf::Color::White);
    gambasx_.setFillColor(sf::Color::White);
    testa_.setFillColor(sf::Color::White);

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


    aggiornaPosizione();
    window_.draw(corpo_);
    window_.draw(bracciadx_);
    window_.draw(bracciasx_);
    window_.draw(gambadx_);
    window_.draw(gambasx_);
    window_.draw(testa_);

    Personaggio::collisione = "";

}

//TODO rimuovi test colllisione
//TODO FIXBUG Collision viene aggiornato inb modo diverso dalla hit box
void Personaggio::aggiornaPosizione() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Personaggio::collisione != "left") {
        x_ -= size_ / 10.0f;
        std::cout << collisione << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Personaggio::collisione != "right") {
        x_ += size_ / 10.0f;
        std::cout << collisione << endl;
    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Personaggio::collisione != "top") {
            y_ -= size_ / 10.0f;
            std::cout << collisione << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Personaggio::collisione != "bottom") {
            y_ += size_ / 10.0f;
            std::cout << collisione << endl;
        }

        // Aggiorna la posizione dei componenti del personaggio
        setPosition(x_,y_);

    }


void Personaggio::setPosition(float x ,float y) {
    corpo_.setPosition(x, y - size_);
    bracciadx_.setPosition(corpo_.getPosition().x + (corpo_.getSize().x), corpo_.getPosition().y);
    bracciasx_.setPosition(corpo_.getPosition().x - (bracciasx_.getSize().x), corpo_.getPosition().y);
    gambasx_.setPosition(corpo_.getPosition().x, y);
    gambadx_.setPosition(corpo_.getPosition().x + ((corpo_.getSize().x / 7) * 4) + 1, y);
    testa_.setPosition(corpo_.getPosition().x, corpo_.getPosition().y - testa_.getRadius() * 2);
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