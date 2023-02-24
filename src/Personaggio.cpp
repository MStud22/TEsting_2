//
// Created by Marco on 23/02/2023.
//

#include "../header/Personaggio.h"

Personaggio::Personaggio(float x, float y, float size, RenderWindow& window) :
        x_(x), y_(y), size_(size), window_(window)
{
    // Imposta i colori dei componenti dello stickman
    corpo_.setFillColor(sf::Color::White);
    braccia_.setFillColor(sf::Color::White);
    gambadx_.setFillColor(sf::Color::White);
    gambasx_.setFillColor(sf::Color::White);
    testa_.setFillColor(sf::Color::White);

    // Imposta le dimensioni dei componenti dello stickman
    corpo_.setSize(sf::Vector2f(size_ / 2, size_ ));
    braccia_.setSize(sf::Vector2f(size_ / 0.7, size_ / 5));
    gambadx_.setSize(sf::Vector2f(size_ / 5, size_ * 1.25 ));
    gambasx_.setSize(sf::Vector2f(size_ / 5, size_ * 1.25 ));

    // Posiziona i componenti dello stickman in relazione agli altri per ottenere una figura distinguibile
    corpo_.setPosition(x_, y_ - size_);
    braccia_.setPosition( corpo_.getPosition().x - (braccia_.getSize().x/3) ,corpo_.getPosition().y);
    gambasx_.setPosition(corpo_.getPosition().x , y_);
    gambadx_.setPosition(corpo_.getPosition().x + ((corpo_.getSize().x/7)*4)+1 , y_);

    // Imposta le dimensioni e il colore della testa
    testa_.setRadius(size_ / 4.5 );

    testa_.setPosition(corpo_.getPosition().x  , corpo_.getPosition().y - testa_.getRadius()*2);
}

void Personaggio::disegna() {


        aggiornaPosizione();
        window_.draw(corpo_);
        window_.draw(braccia_);
        window_.draw(gambadx_);
        window_.draw(gambasx_);
        window_.draw(testa_);
    Personaggio::collisione = "";

}

void Personaggio::aggiornaPosizione()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Personaggio::collisione != "left") {
            x_ -= size_ / 10.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Personaggio::collisione != "right") {
            x_ += size_ / 10.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Personaggio::collisione != "top") {
            y_ -= size_ / 10.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Personaggio::collisione != "bottom") {
            y_ += size_ / 10.0f;
        }

        // Aggiorna la posizione dei componenti del personaggio
        setPosition(x_,y_);

    }

    float Personaggio::getPositionx()
    {
        return corpo_.getPosition().x;
}

float Personaggio::getPositiony()
{
    return   corpo_.getPosition().y;
}

void Personaggio::setPosition(float x ,float y)
{
    corpo_.setPosition(x, y - size_);
    braccia_.setPosition(corpo_.getPosition().x - (braccia_.getSize().x/3), corpo_.getPosition().y);
    gambasx_.setPosition(corpo_.getPosition().x, y);
    gambadx_.setPosition(corpo_.getPosition().x + ((corpo_.getSize().x/7)*4)+1, y);
    testa_.setPosition(corpo_.getPosition().x, corpo_.getPosition().y - testa_.getRadius()*2);
}


//restituisce la hit box del personaggio
sf::FloatRect Personaggio::getCollisionRect() const {
    // Calcola la posizione e le dimensioni del rettangolo di collisione del personaggio
    float left = corpo_.getPosition().x;
    float top = corpo_.getPosition().y - corpo_.getSize().y;
    float right = corpo_.getPosition().x + corpo_.getSize().x;
    float bottom = corpo_.getPosition().y;

    left = std::min(left, braccia_.getPosition().x - braccia_.getSize().x / 3);
    top = std::min(top, braccia_.getPosition().y);
    right = std::max(right, gambadx_.getPosition().x + gambadx_.getSize().x);
    bottom = std::max(bottom, gambadx_.getPosition().y + gambadx_.getSize().y);

    left = std::min(left, gambasx_.getPosition().x);
    top = std::min(top, gambasx_.getPosition().y);
    right = std::max(right, gambasx_.getPosition().x + gambasx_.getSize().x);
    bottom = std::max(bottom, gambasx_.getPosition().y + gambasx_.getSize().y);

    left = std::min(left, testa_.getPosition().x - testa_.getRadius());
    top = std::min(top, testa_.getPosition().y - testa_.getRadius());
    right = std::max(right, testa_.getPosition().x + testa_.getRadius());
    bottom = std::max(bottom, testa_.getPosition().y + testa_.getRadius());

    return sf::FloatRect(left, top, right - left, bottom - top);
}


void Personaggio::Collision( string bordo) {
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