//
// Created by Marco on 20/09/2023.
//
#include <iostream>
#include "../header/Fighting_Window.h"


Fighting_Window::Fighting_Window(RenderWindow &window, Personaggio *p) : window(window) {

}

void Fighting_Window::draw() {

    window.clear(sf::Color::Black);

    //assegno ad ogni stringa il font
    fontText.loadFromFile("../assets/spqri.ttf");


    fightText.setFont(fontText);
    runText.setFont(fontText);
    talkText.setFont(fontText);
    itemsText.setFont(fontText);

    fightText.setCharacterSize(20);
    runText.setCharacterSize(20);
    talkText.setCharacterSize(20);
    itemsText.setCharacterSize(20);

    fightText.setFillColor(sf::Color::White);
    runText.setFillColor(sf::Color::White);
    talkText.setFillColor(sf::Color::White);
    itemsText.setFillColor(sf::Color::White);

    fightText.setStyle(sf::Text::Bold);
    runText.setStyle(sf::Text::Bold);
    talkText.setStyle(sf::Text::Bold);
    itemsText.setStyle(sf::Text::Bold);

    fightText.setString("fight!");
    runText.setString("RUN!");
    talkText.setString("talk?");
    itemsText.setString("items");

    /////////////////////////////////////////////////////////////////////////////////

    sf::FloatRect bounds;
    float y = 100.f;
    bounds = fightText.getGlobalBounds();

    Fight_Rect2.setSize(sf::Vector2f(window.getSize().x, window.getSize().y / 5 + 20));
    Fight_Rect2.setPosition(0, window.getSize().y / 5 * 4 - 20);
    Fight_Rect2.setFillColor(sf::Color::White);
    window.draw(Fight_Rect2);

    Fight_Rect1.setSize(sf::Vector2f(window.getSize().x - 40, window.getSize().y / 5 - 20));
    Fight_Rect1.setPosition(20, window.getSize().y / 5 * 4);
    Fight_Rect1.setFillColor(sf::Color::Black);
    window.draw(Fight_Rect1);

    fightText.setOrigin(0, 0);
    fightText.setPosition(window.getSize().x / 20.f + 15, (window.getSize().y / 5) * 4 + 20);
    window.draw(fightText);

    runText.setOrigin(0, 0);
    runText.setPosition(fightText.getPosition().x, fightText.getPosition().y + 40);
    window.draw(runText);

    talkText.setOrigin(0, 0);
    talkText.setPosition(fightText.getPosition().x + 170, fightText.getPosition().y);
    window.draw(talkText);

    itemsText.setOrigin(0, 0);
    itemsText.setPosition(fightText.getPosition().x + 170, fightText.getPosition().y + 40);
    window.draw(itemsText);

    for (int i = 0; i < (p->getHp() / 5); ++i) {
        sf::RectangleShape Bar(sf::Vector2f(30, 20));
        Bar.setPosition((window.getSize().x / 2) + (35 * i), fightText.getPosition().y);
        Bar.setFillColor(sf::Color::Green);
        Health_Bar.push_back(Bar);
    }

    for (auto &HP: Health_Bar) {
        window.draw(HP);
    }
    window.display();
}

Personaggio *Fighting_Window::getP() const {
    return p;
}

void Fighting_Window::setP(Personaggio *p) {
    Fighting_Window::p = p;
}

