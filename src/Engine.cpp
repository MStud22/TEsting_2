
#include <iostream>
#include <mqoai.h>
#include "../header/Engine.h"

#include "../header/Personaggio.h"
#include "../header/Room.h"
#include "../header/Menu.h"
#include "SnakeAnimation.cpp"
#include "../header/Scelta_personaggio.h"


const sf::Time Engine::


        TimeperFrame = seconds(
                1.f / 60.f);        //creiamo una costante che definisce il Frame come un sessantesimo di secondo

Engine::Engine() {
    resolution = Vector2f(800, 600); // dimensioni finestra
    window.create(VideoMode(resolution.x, resolution.y), "Test",
                  Style::Default);  //creazione finestra,risoluzione,nome,stile
    window.setFramerateLimit(FPS);


}

void Engine::run() {

    //Main game loop , il gioco viene processato dalla classe engine

    sf::Texture background;
    background.loadFromFile("../assets/background/background.png");
    Sprite sprite;
    sprite.setTexture(background);
    sprite.setScale(4, 4);


    //implementazione menu
    Menu menu(window);
    bool visible = true;  // usiamo questa variabile booleana per controllare la visibilità del testo
    //voglio che il nostro testo non lampeggi e sioa ben visibile all'occhio umano

    //implementazione scelta personaggio
    Scelta_personaggio chose(window);


    //animazione Switch / stanze
    Clock clock;
    SnakeAnimation snake(window, 10, 0.2f);
    float dt = clock.restart().asSeconds();
    bool AnimatingSnake = false;

    //CREA IL PERSONAGGIO DOPO HE è STATA SCELTA LA CLASSE
    Personaggio p(100, 200, 30, window);

    //stanza e variabili di appoggio per il suo funzionamento
    Room room(800, 400);

    //todo rimuovi o intgra controllo


    while (window.isOpen()) {

        /*
         * CODICE CHE CONTROLLA STANZE PARTICOLARI O STANZE INIZIALI
         */

        if (startMenu) {

            if (clock.getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
            {
                visible = !visible; // invertiamo la visibilità del testo
                clock.restart(); // riavviamo l'orologio
            }
            if (visible)
                menu.draw();
            input();

        }


        if (scelta_personaggio) {
            if (clock.getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
            {
                visible = !visible; // invertiamo la visibilità del testo
                clock.restart(); // riavviamo l'orologio
            }
            if (visible)
                chose.draw();
            input();
            if (choise_done) {
                p.setClasse(classe);
                p.setTexture(classe);
            }

            cout << classe << endl;
        }


        /*controlla se il gioco sta effettuando una animazione o una cinematica */

        /*
         *  CODICE DI MOVIMENTO E GIOCO VERO E PROPRIO
         */

        if (!AnimatingSnake && !startMenu && !scelta_personaggio) {
            window.clear();
            window.draw(sprite);
            room.drawRoom(window);
            p.disegna();

            input();//prima di aggiornare lo schermo , controlla per gli input



            /*////////////////////////////////////////////////////////////////////////////////////
                   CODICE PER LIMITARE IL MOVIMENTO
              ///////////////////////////////////////////////////////////////////////////////////*/
            if (p.getCollisionRect().intersects(room.top.getGlobalBounds())) {
                p.Collision("top");
            }
            if (p.getCollisionRect().intersects(room.bottom.getGlobalBounds())) {
                p.Collision("bottom");
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
            if (p.getCollisionRect().intersects((room.entrance.getGlobalBounds()))) {
                window.clear();
                AnimatingSnake = true;

            }
            window.display();
        }






        /*///////////////////////////////////////////////////////////////////////////
               //GENERAZIONE NUOVA STANZA QUANDO SI RAGGIUNGE L'ENTRATA
        //////////////////////////////////////////////////////////////////////////*/

        /* ///////////////////////////////// ANIMAZIONE///////////////////////////////////////*/

        while (AnimatingSnake && !startMenu && !scelta_personaggio) {
            snake.update(dt);
            window.clear();
            snake.draw();
            if (snake.isFinished()) {
                AnimatingSnake = false;
                room.Pick_Room();
                snake.Reset();
                p.setPosition(100, 200);
                break;
            }
            window.display();
        }

        frames = getElapsedFrames();

    }
}


