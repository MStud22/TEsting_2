#include "../header/Menu.h"

Menu::Menu(sf::RenderWindow &window) : window_(window) {};

void Menu::draw(const std::vector<std::string> &menu_items) {
    window_.clear(sf::Color::Black);
    sf::Font font;
    font.loadFromFile("../assets/Thor.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    float y = 100.f;
    for (const auto &item: menu_items) {
        text.setString(item);
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
        text.setPosition(window_.getSize().x / 2.f, y);
        window_.draw(text);
        y += 75.f;
    }

    window_.display();
}


