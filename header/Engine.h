
#ifndef TESTING_2_ENGINE_H
#define TESTING_2_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


using namespace sf; //abbreviazione di sfml class per richimare la libreria piu veloemente (non bisogna scriverla)
using namespace std; //stessa cosa
class Engine {
private:
    //Window
    Vector2f resolution;

    const unsigned int FPS = 60;
    static const Time TimeperFrame;


public:
    Engine();

    RenderWindow window;
    void input();


    //abbiamo bisogno di un main loop per effettture il run
    void run();

};


#endif //TESTING_2_ENGINE_H
