//
// Created by Marco on 23/02/2023.
//
#include "../header/Engine.h"

void Engine::input() {
    Event event{};

    while (window.pollEvent(event)) {
        //controlliamo l'evento di chiusura
        if (event.type == Event::Closed)
            window.close();

        //controlliamo input (controllo input da tastiera)
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
        if (startMenu) {
            if (event.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed((Keyboard::Enter))) {
                    startMenu = false;
                    scelta_personaggio = true;

                }
            }
        }
        if (scelta_personaggio)
            if (event.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed((Keyboard::Space))) {
                    scelta_personaggio = false;

                }
            }


    }
}