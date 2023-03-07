#include "../header/Menu.h"

Menu::Menu(sf::RenderWindow &window) : window_(window) {};

void Menu::draw() {

    window_.clear(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("../assets/Thor.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    sf::Font font2;
    font2.loadFromFile("../assets/spqri.ttf");
    sf::Text text2;
    text2.setFont(font2);
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold);

    float y = 100.f;

    text.setString(Title);
    text2.setString(Start);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(window_.getSize().x / 2.f, y);
    window_.draw(text);


    y += 75.f;
    bounds = text2.getLocalBounds();
    text2.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text2.setPosition(window_.getSize().x / 2.f, y);
    window_.draw(text2);


    window_.display();
}


