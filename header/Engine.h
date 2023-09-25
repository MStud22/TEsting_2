
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
    bool choise_done = false;
    const unsigned int FPS = 60;
    static const Time TimeperFrame;


public:
    Engine();

    RenderWindow window;

    void input();

    static int getElapsedFrames();

    bool startMenu = true;
    bool scelta_personaggio = false;
    bool fight = false;

    //abbiamo bisogno di un main loop per effettture il run
    void run();

    int frames;

    string classe = "";

    String getClasse();
};


#endif //TESTING_2_ENGINE_H
