#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Engine.h"

using namespace sf;

class SnakeAnimation {
private:
    RenderWindow &window;
    RectangleShape head;
    std::vector<RectangleShape> body;
    float speed = 0.5f;  // velocità del serpente (in pixel al secondo)
    float timeElapsed = 0;  // tempo trascorso dall'ultimo aggiornamento
public:
    SnakeAnimation(RenderWindow &window) : window(window) {
        // impostazioni della testa del serpente
        head.setFillColor(Color::Green);
        head.setSize(Vector2f(20, 20));
        head.setOrigin(head.getSize() / 2.f);
        head.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

        // inizializzazione del corpo del serpente
        for (int i = 0; i < 4; i++) {
            RectangleShape rect = head;
            rect.setPosition(head.getPosition().x - i * head.getSize().x, head.getPosition().y);
            body.push_back(rect);
        }
    }

    void update(float dt) {
        timeElapsed += dt;
        if (timeElapsed >= 1.f / speed) {
            timeElapsed -= 1.f / speed;

            // aggiornamento della posizione del serpente
            Vector2f prevPos = head.getPosition();
            head.move(head.getSize().x, 0);

            if (head.getPosition().x > window.getSize().x) {
                head.setPosition(-head.getSize().x / 2.f, head.getPosition().y);
            }

            for (int i = 0; i < body.size(); i++) {
                Vector2f temp = body[i].getPosition();
                body[i].setPosition(prevPos);
                prevPos = temp;
            }
        }
    }


    void draw() {
        window.draw(head);
        for (int i = 0; i < body.size(); i++) {
            cout << "ecchelo" << endl;
            window.draw(body[i]);
        }
    }
};