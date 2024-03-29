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

    //imposta tetxture
    texture.loadFromFile("../assets/wall.png");
    //carica texture sui muri
    Room::top.setTexture(&texture);
    Room::top.setTextureRect(sf::IntRect(0, 0, 20, 30));
    Room::bottom.setTexture(&texture);
    Room::left.setTexture(&texture);
    Room::right.setTexture(&texture);

    Room::top.setFillColor(sf::Color::White);
    Room::bottom.setFillColor(sf::Color::White);
    Room::left.setFillColor(sf::Color::White);
    Room::right.setFillColor(sf::Color::White);

    Room::top.setPosition(0.f, 0.f);
    Room::bottom.setPosition(0.f, height_ - 10.f);
    Room::left.setPosition(0.f, 0.f);
    Room::right.setPosition(width_ - 10.f, 0.f);

    OuterWalls.push_back(top);
    OuterWalls.push_back(bottom);
    OuterWalls.push_back(left);
    OuterWalls.push_back(right);
    //crea le pareti interne
    Pick_Room();
}



void Room::Pick_Room() {
    //attraverso un random , scegli tra un numero pre impostato di stanze


    // Genera un numero casuale compreso tra 1 e 5
    std::srand(std::time(nullptr));
    int room_number = std::rand() % 3 + 1;



    if (room_number == 1) {
        genera_FANGS();
    }
    if (room_number == 2) {
        genera_ZIGZAG();
    }
    if (room_number == 3) {
        genera_LONGCORRIDOR();
    }
}



void Room::drawRoom(sf::RenderWindow &window) {
    window.draw(background_image);
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);
    window.draw(exit);

    /*
    for (const auto &wall: innerWalls) {
        window.draw(wall);
    }
    */

    //i muri posso generati e lasciati invisibili per poter permettere di integrare con il design di gicoo

}


void Room::genera_FANGS() {
    float wallWidth = 30.f;
    float wallHight = height_ / 3;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/background_FANGS.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);
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
        wall.setTexture(&texture);
    }

    // Crea l'ingresso e l'uscita


    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));


    Room::entrance.setFillColor(sf::Color::Green);


    Room::entrance.setPosition(width_ - (width_ / 10), height_ / 2);
}

void Room::genera_ZIGZAG() {
    float wallWidth = 30.f;
    float wallHight = height_ - 150.f;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/background_ZIGZAG.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);
    //GENERA I WALLS
    //1
    sf::RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(width_ / 5, -100);
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
        wall.setFillColor(sf::Color::Red);

    }

    // Crea l'ingresso e l'uscita

    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));


    Room::entrance.setFillColor(sf::Color::Green);


    Room::entrance.setPosition(width_ - (width_ / 10), height_ / 2);
}

void Room::genera_LONGCORRIDOR() {
    float wallWidth = width_;
    float wallHight = height_ / 3;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/LONG_CORRIDOR.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);
    //GENERA I WALLS
    //1
    sf::RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(0, 0);
    innerWalls.push_back(wall);
    //2
    sf::RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition(0, (height_ / 3) * 2);
    innerWalls.push_back(wall2);

    //rende tutti i muri  su Innerwalls bianchi
    for (auto &wall: innerWalls) {
        wall.setFillColor(sf::Color::White);
        wall.setTexture(&texture);

    }

    // Crea l'ingresso e l'uscita


    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));


    Room::entrance.setFillColor(sf::Color::Green);

    Room::entrance.setPosition(width_ - (width_ / 10), height_ / 2);
}

//TODO sviluppare la stanza di scelta personaggio, dovra essere una stanza speciale che si genera solo a inizio partita e mai più

