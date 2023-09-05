//
// Created by Marco on 23/02/2023.
//
#include <iostream>
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
                if (Keyboard::isKeyPressed((Keyboard::Num1))) {
                    scelta_personaggio = false;                                     //determina in che "situazione" ci troviamo
                    Engine::classe = "knight";
                    choise_done = true;
                }
                if (Keyboard::isKeyPressed((Keyboard::Num2))) {
                    scelta_personaggio = false;
                    Engine::classe = "thief";
                    choise_done = true;
                }
                if (Keyboard::isKeyPressed((Keyboard::Num3))) {
                    scelta_personaggio = false;
                    Engine::classe = "Mage";
                    choise_done = true;
                }

                if (Keyboard::isKeyPressed((Keyboard::Escape))) {
                    window.close();

                }
            }


    }
}