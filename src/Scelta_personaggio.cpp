//
// Created by Marco on 19/04/2023.
//

#include <iostream>
#include "../header/Scelta_personaggio.h"

Scelta_personaggio::Scelta_personaggio(sf::RenderWindow &window) : window_(window) {}

void Scelta_personaggio::draw() {

    window_.clear(sf::Color::Black);
    //Font per il titolo e setting per la scritta
    sf::Font font2;
    font2.loadFromFile("../assets/spqri.ttf");
    sf::Text text;
    text.setFont(font2);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    //font per i nomi dei personaggi
    sf::Font name;
    name.loadFromFile("../assets/Thor.ttf");
    //cavaliere
    sf::Text knight;
    knight.setFont(name);
    knight.setCharacterSize(20);
    knight.setFillColor(sf::Color::White);
    knight.setStyle(sf::Text::Bold);
    knight.setString(Knight);
    //ladro
    sf::Text thief;
    thief.setFont(name);
    thief.setCharacterSize(20);
    thief.setFillColor(sf::Color::White);
    thief.setStyle(sf::Text::Bold);
    thief.setString(Thief);
    //mago
    sf::Text mage;
    mage.setFont(name);
    mage.setCharacterSize(20);
    mage.setFillColor(sf::Color::White);
    mage.setStyle(sf::Text::Bold);
    mage.setString(Mage);
    float y = 100.f;

    //posizione di TITLE
    text.setString(Title);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(window_.getSize().x / 2.f, y);
    window_.draw(text);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //posizione delle altre stringhe
    bounds = knight.getLocalBounds();
    knight.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    knight.setPosition(100, (window_.getSize().y / 5) * 4);
    window_.draw(knight);

    bounds = thief.getLocalBounds();
    thief.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    thief.setPosition(window_.getSize().x / 4 + 100, (window_.getSize().y / 5) * 4);
    window_.draw(thief);

    bounds = mage.getLocalBounds();
    mage.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    mage.setPosition(window_.getSize().x / 2 + 100, (window_.getSize().y / 5) * 4);
    window_.draw(mage);
    //////////////////////////////////////////////////////////////////////////////////////////////////

    window_.display();
}