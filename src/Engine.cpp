
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


    //impostazione sfondo , e lo adata alla finestra

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("../assets/prato.jpg");
    Vector2u textureSize = backgroundTexture.getSize();
    Vector2u windowSize = window.getSize();
    Sprite background(backgroundTexture);

    // calcola la scala orizzontale e verticale
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y;

// imposta la scala dello sprite
    background.setScale(scaleX, scaleY);



    //Main game loop , il gioco viene processato dalla classe engine
    Personaggio p(100, 200, 30, window);

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

        //TODO fix collisioni
        //TODO: problema : vengono rilevati correttamente i rettangoli degli oggetti (test rosso) ma il personjaggio non si ferma correttamente quando riceve l'input
        if (p.getCollisionRect().intersects(room.top.getGlobalBounds())) {
            p.Collision("top");
        }
        if (p.getCollisionRect().intersects(room.bottom.getGlobalBounds())) {
            p.Collision("bottom");
            p.corpo_.setFillColor(sf::Color::White);        //todo rimuovi test
        }
        if (p.getCollisionRect().intersects(room.left.getGlobalBounds())) {
            p.Collision("left");
        }
        if (p.getCollisionRect().intersects(room.right.getGlobalBounds())) {
            p.Collision("right");
        }

        /*fixbug update ,update classe get collision direction , non rileva correttamente i rettangoli*/



        //codice per collisione con muri interni
        for (const auto &wall: room.innerWalls) {
            if (p.getCollisionRect().intersects(wall.getGlobalBounds())) {


                //todo rimuovi test
                sf::RectangleShape hitbox;
                hitbox.setSize(Vector2f(wall.getGlobalBounds().width, wall.getGlobalBounds().height));
                hitbox.setPosition(wall.getPosition().x, wall.getPosition().y);
                hitbox.setFillColor(sf::Color::Blue);
                sf::RectangleShape hitbox_p;
                hitbox_p.setSize(Vector2f(p.getCollisionRect().width, p.getCollisionRect().height));
                hitbox_p.setPosition(p.getCollisionRect().left, p.getCollisionRect().top);
                hitbox_p.setFillColor(sf::Color::Yellow);
                window.draw(hitbox);
                window.draw(hitbox_p);
                //todo rimuovi test

                p.Collision(p.getCollisionDirection(wall.getGlobalBounds()));

                std::cout << "collisione muro : " + p.collisione << endl;                //todo rimuovi test
            }
        }





        /*///////////////////////////////////////////////////////////////////////////
               //GENERAZIONE NUOVA STANZA QUANDO SI RAGGIUNGE L'ENTRATA
        //////////////////////////////////////////////////////////////////////////*/

        if (p.getCollisionRect().intersects((room.entrance.getGlobalBounds()))) {
            room.Pick_Room();
        }
        window.display();


    }
}



