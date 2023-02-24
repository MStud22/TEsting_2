//
// Created by Marco on 23/02/2023.
//

#include "../header/Room.h"


Room::Room(int width_, int height_) : width_(width_),height_(height_) {
    srand(time(NULL));

// Crea i rettangoli che delimitano la stanza
    Room::top.setSize(sf::Vector2f(width_, 10.f));
    Room::bottom.setSize(sf::Vector2f(width_, 10.f));
    Room::left.setSize(sf::Vector2f(10.f, height_));
    Room::right.setSize(sf::Vector2f(10.f, height_));

    Room::top.setFillColor(sf::Color::White);
    Room::bottom.setFillColor(sf::Color::White);
    Room::left.setFillColor(sf::Color::White);
    Room::right.setFillColor(sf::Color::White);

    Room::top.setPosition(0.f, 0.f);
    Room::bottom.setPosition(0.f, height_ - 10.f);
    Room::left.setPosition(0.f, 0.f);
    Room::right.setPosition(width_ - 10.f, 0.f);



// Crea l'ingresso e l'uscita
    float x = static_cast<float>(rand() % (width_ - 40) + 20);
    float y = static_cast<float>(rand() % (height_ - 40) + 20);
    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));
    Room::exit.setSize(sf::Vector2f(20.f, 20.f));

    Room::entrance.setFillColor(sf::Color::Green);
    Room::exit.setFillColor(sf::Color::Red);

    Room::entrance.setPosition(x, y);

    if (x < width_ / 2.f) {
        Room::exit.setPosition(width_ - 30.f, y);
    } else {
        Room::exit.setPosition(0.f, y);
    }

    //crea le pareti interne
    generateInnerWalls();
}


void Room::generateInnerWalls() {
    float wallWidth = 10.f;
    float minWidth = 30.f;

    // Generate walls along top and bottom edges
    for (float x = wallWidth; x < width_ - minWidth; ) {
        float w = static_cast<float>(rand() % static_cast<int>((width_ - x - minWidth) / 2) + minWidth);
        float h = wallWidth * 2.f;
        float y = static_cast<float>(rand() % static_cast<int>(height_ - h - wallWidth) + wallWidth);

        sf::RectangleShape wall(sf::Vector2f(w, h));
        wall.setPosition(x, y);
        wall.setFillColor(sf::Color::White);
        innerWalls.push_back(wall);

        x += w + wallWidth;
    }

    // Generate walls along left and right edges
    for (float y = wallWidth * 2.f; y < height_ - wallWidth * 2.f - minWidth; ) {
        float w = wallWidth * 2.f;
        float h = static_cast<float>(rand() % static_cast<int>((height_ - y - minWidth) / 2) + minWidth);
        float x = static_cast<float>(rand() % static_cast<int>(width_ - w - wallWidth) + wallWidth);

        sf::RectangleShape wall(sf::Vector2f(w, h));
        wall.setPosition(x, y);
        wall.setFillColor(sf::Color::White);
        innerWalls.push_back(wall);

        y += h + wallWidth;
    }

    // Generate walls between top and bottom edges
    for (float x = wallWidth * 2.f; x < width_ - wallWidth * 2.f - minWidth; ) {
        float w = static_cast<float>(rand() % static_cast<int>(width_ - x - wallWidth - minWidth) + minWidth);
        float h = wallWidth;
        float y;

        if (rand() % 2 == 0) {
            y = wallWidth;
        } else {
            y = height_ - wallWidth * 2.f;
        }

        sf::RectangleShape wall(sf::Vector2f(w, h));
        wall.setPosition(x, y);
        wall.setFillColor(sf::Color::White);
        innerWalls.push_back(wall);

        x += w + wallWidth;
    }

    // Generate walls between left and right edges
    for (float y = wallWidth * 3.f; y < height_ - wallWidth * 3.f - minWidth; ) {
        float w = wallWidth;
        float h = static_cast<float>(rand() % static_cast<int>(height_ - y - wallWidth - minWidth) + minWidth);
        float x;

        if (rand() % 2 == 0) {
            x = wallWidth;
        } else {
            x = width_ - wallWidth * 2.f;
        }

        sf::RectangleShape wall(sf::Vector2f(w, h));
        wall.setPosition(x, y);
        wall.setFillColor(sf::Color::White);
        innerWalls.push_back(wall);

        y += h + wallWidth;
    }
}
void Room::drawRoom(sf::RenderWindow &window) {
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);
    window.draw(exit);
    for (const auto &wall : innerWalls) {
        window.draw(wall);
    }
}





