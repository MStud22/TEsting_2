
#include <iostream>
#include "../header/Engine.h"
#include "../header/Personaggio.h"
#include "../header/Room.h"


const sf::Time Engine::TimeperFrame = seconds(1.f/60.f);        //creiamo una costante che definisce il Frame come un sessantesimo di secondo

Engine::Engine()
{
    resolution = Vector2f (800,600); // dimensioni finestra
    window.create(VideoMode(resolution.x,resolution.y),"Test",Style::Default);  //creazione finestra,risoluzione,nome,stile
    window.setFramerateLimit(FPS);

}

void Engine::run()
{


    //Main game loop , il gioco viene processato dalla classe engine


    Personaggio p(100, 200, 30, window);
    //stanza e variabili di appoggio per il suo funzionamento
    Room room(800,400);


    while(window.isOpen() )
    {
        window.clear();
        room.drawRoom(window);
        p.disegna();
        input();//prima di aggiornare lo scherma , controlla per gli input


        /*////////////////////////////////////////////////////////////////////////////////////
               CODICE PER LIMITARE IL MOVIMENTO
          ///////////////////////////////////////////////////////////////////////////////////*/


        if (p.getCollisionRect().intersects(room.top.getGlobalBounds())) {
            p.Collision("top");
        }
        if (p.getCollisionRect().intersects(room.bottom.getGlobalBounds())) {
            p.Collision("bottom");
            p.corpo_.setFillColor(sf::Color::White);
        }
        if (p.getCollisionRect().intersects(room.left.getGlobalBounds())) {
            p.Collision("left");
        }
        if (p.getCollisionRect().intersects(room.right.getGlobalBounds())) {
            p.Collision("right");
        }
        if (p.getCollisionRect().intersects(room.top.getGlobalBounds()) ||
            p.getCollisionRect().intersects(room.bottom.getGlobalBounds()) ||
            p.getCollisionRect().intersects(room.left.getGlobalBounds()) ||
            p.getCollisionRect().intersects(room.right.getGlobalBounds())) {
            for (const auto &wall: room.OuterWalls) {
                if (p.getCollisionRect().intersects(wall.getGlobalBounds())) {
                    p.Collision(p.getCollisionDirection(wall.getGlobalBounds()));
                }
            }
        }
        //codice per collisione con muri interni
        for (const auto &wall: room.innerWalls) {
            if (p.getCollisionRect().intersects(wall.getGlobalBounds())) {
                p.Collision(p.getCollisionDirection(wall.getGlobalBounds()));
            }
        }





        /*///////////////////////////////////////////////////////////////////////////
               //GENERAZIONE NUOVA STANZA QUANDO SI RAGGIUNGE L'ENTRATA
        //////////////////////////////////////////////////////////////////////////*/

        if (p.getCollisionRect().intersects((room.entrance.getGlobalBounds()))) {
            room.Pick_Room();
            p.setPosition(100, 200);


            //TODO testing
            std::cout << p.corpo_.getPosition().x << endl;
            std::cout << p.x_ << endl;
            sf::RectangleShape test;
            test.setSize(p.corpo_.getSize());
            test.setPosition(100, 200);
            test.setFillColor(sf::Color::Magenta);
            window.draw(test);
            //TODO finish testing

        }
        window.display();


    }
}



