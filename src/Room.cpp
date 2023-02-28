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





    //crea le pareti interne
    Pick_Room();
}

//GENERA IN MODO AUTOMATICO PARETI INTERNE VEROSIMILI
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

void Room::Pick_Room() {
    //attraverso un random , scegli tra un numero pre impostato di stanze

    // Genera un numero casuale compreso tra 1 e 5
    std::srand(std::time(nullptr));
    int room_number = std::rand() % 2 + 1;


    if (room_number == 1) {
        genera_FANGS();
    }
    if (room_number == 2) {
        genera_ZIGZAG();
    }
}



void Room::drawRoom(sf::RenderWindow &window) {
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);
    window.draw(exit);
    for (const auto &wall: innerWalls) {
        window.draw(wall);
    }
}


void Room::genera_FANGS() {
    float wallWidth = 30.f;
    float wallHight = height_ / 3;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();

    //GENERA I WALLS
    //1
    sf::RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(width_ / 4, 0);
    innerWalls.push_back(wall);
    //2
    sf::RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition(width_ / 4, height_ - (wallHight));
    innerWalls.push_back(wall2);
    //3
    sf::RectangleShape wall3(sf::Vector2f(wallWidth, wallHight));
    wall3.setPosition((width_ / 4) * 3, 0);
    innerWalls.push_back(wall3);
    //4
    sf::RectangleShape wall4(sf::Vector2f(wallWidth, wallHight));
    wall4.setPosition((width_ / 4) * 3, height_ - (wallHight));
    innerWalls.push_back(wall4);

    sf::RectangleShape CenterCube(sf::Vector2f(wallHight, wallHight));
    CenterCube.setPosition(width_ / 2 - wallWidth * 2, (height_ / 3));
    innerWalls.push_back(CenterCube);

    //rende tutti i muri  su Innerwalls bianchi
    for (auto &wall: innerWalls) {
        wall.setFillColor(sf::Color::White);
    }

    // Crea l'ingresso e l'uscita

    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));
    Room::exit.setSize(sf::Vector2f(20.f, 20.f));

    Room::entrance.setFillColor(sf::Color::Green);
    Room::exit.setFillColor(sf::Color::Red);

    Room::entrance.setPosition(width_ / 10, height_ / 2);
    Room::exit.setPosition(width_ - (width_ / 10), height_ / 2);
}

void Room::genera_ZIGZAG() {
    float wallWidth = 30.f;
    float wallHight = height_ - 150.f;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    //GENERA I WALLS
    //1
    sf::RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(width_ / 5, 0);
    innerWalls.push_back(wall);
    //2
    sf::RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition((width_ / 2), height_ - wallHight);
    innerWalls.push_back(wall2);
    //3
    sf::RectangleShape wall3(sf::Vector2f(wallWidth, wallHight));
    wall3.setPosition((width_ / 5) * 4, 0);
    innerWalls.push_back(wall3);

    //rende tutti i muri  su Innerwalls bianchi
    for (auto &wall: innerWalls) {
        wall.setFillColor(sf::Color::White);
    }

    // Crea l'ingresso e l'uscita

    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));
    Room::exit.setSize(sf::Vector2f(20.f, 20.f));

    Room::entrance.setFillColor(sf::Color::Green);
    Room::exit.setFillColor(sf::Color::Red);

    Room::entrance.setPosition(width_ / 10, height_ / 2);
    Room::exit.setPosition(width_ - (width_ / 10), height_ / 2);
}


