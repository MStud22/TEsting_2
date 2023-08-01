#include <iostream>
#include "../header/Engine.h"
int main() {
    srand(time(NULL));
    Engine engine; //definiamo l'oggetto engine dalla classe (fa il run del costruttore)
    engine.run(); // fa il run della funzione

    return 0;
}


