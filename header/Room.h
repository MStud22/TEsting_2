#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#ifndef TESTING_2_ROOM_H
#define TESTING_2_ROOM_H

class Room {
public:
    int width_;
    int height_;
    sf::RectangleShape top ;
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::RectangleShape bottom;
    sf::RectangleShape entrance;
    sf::RectangleShape exit;
    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> innerWalls;
    std::vector<sf::RectangleShape> OuterWalls;

    Room(int width_, int height_);

    void drawRoom(sf::RenderWindow &window);

    void Sviluppo_stanza();

    void Pick_Room();

    void genera_FANGS();

    void genera_ZIGZAG();

    void genera_LONGCORRIDOR();

private:
    sf::Texture texture;
    sf::Sprite background_image;
    sf::Texture background_texture;


};


#endif //TESTING_2_ROOM_H
