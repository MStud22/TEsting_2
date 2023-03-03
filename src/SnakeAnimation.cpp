#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Engine.h"

using namespace sf;

class SnakeAnimation {
private:
    RenderWindow &window;
    RectangleShape head;
    std::vector<RectangleShape> body;
    float speed;  // velocità del serpente (in pixel al secondo)
    float timeElapsed = 0;  // tempo trascorso dall'ultimo aggiornamento
    bool finished = false;
public:
    SnakeAnimation(sf::RenderWindow &window, int numRectangles, float speed) : window(window), speed(speed) {
        // impostazioni della testa del serpente
        head.setFillColor(Color::Green);
        head.setSize(Vector2f(20, 20));
        head.setOrigin(head.getSize() / 2.f);
        head.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

        // inizializzazione del corpo del serpente
        for (int i = 0; i < numRectangles; i++) {
            RectangleShape rect = head;
            rect.setPosition(head.getPosition().x - i * head.getSize().x, head.getPosition().y);
            body.push_back(rect);
        }
    }

    void update(float dt) {
        timeElapsed += dt;
        //problemi causati dall'if di controllo che non entrava nella funzione
            timeElapsed -= 1.f / speed;

            // aggiornamento della posizione del serpente
            Vector2f prevPos = head.getPosition();
        cout << "posizione testa : " << head.getPosition().x << endl;
        head.move(head.getSize().x, 0);
        cout << "posizione testa : " << head.getPosition().x << endl;

            if (head.getPosition().x > window.getSize().x) {
                head.setPosition(-head.getSize().x / 2.f, head.getPosition().y);
                finished = true;
            }

            for (int i = 0; i < body.size(); i++) {
                Vector2f temp = body[i].getPosition();
                body[i].setPosition(prevPos);
                prevPos = temp;
            }

    }


    void draw() {
        window.draw(head);
        for (int i = 0; i < body.size(); i++) {


            window.draw(body[i]);
        }
    }

    //"isFinished" che restituisce il valore del flag "finished"
    bool isFinished() const {
        return finished;
    }
};