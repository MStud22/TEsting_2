
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
    Personaggio p (400, 300, 30, window);

    Room room(800,400);

    while(window.isOpen() )
    {
        window.clear();
        room.drawRoom(window);
        p.disegna();
        input();//prima di aggiornare lo scherma , controlla per gli input


       /*////////////////////////////////////////////////////////////////////////////////////
              CODICE PER LIMITARE IL MOVIMENTO ALL'INTERNO DELLA FINESTRA
         ///////////////////////////////////////////////////////////////////////////////////          */

        if(p.getCollisionRect().intersects(room.top.getGlobalBounds()))
        {
            p.Collision("top");
        }
        if(p.getCollisionRect().intersects(room.bottom.getGlobalBounds()))
        {
            p.Collision("bottom");
        }
        if(p.getCollisionRect().intersects(room.left.getGlobalBounds()))
        {
            p.Collision("left");
        }
        if(p.getCollisionRect().intersects(room.right.getGlobalBounds()))
        {
            p.Collision("right");
        }

        for (const auto &wall : room.innerWalls) {
            if(p.testa_.getGlobalBounds().intersects(wall.getGlobalBounds()))
            {
                p.Collision("top");
            }
        }





        /////////////////////////////////////////////////////////////////////////////
               //GENERAZIONE NUOVA STANZA QUANDO SI RAGGIUNGE L'ENTRATA
        ////////////////////////////////////////////////////////////////////////////
        if(p.getCollisionRect().intersects((room.entrance.getGlobalBounds())))
        {
           room.Pick_Room();
        }
        window.display();



        // Impedisci al personaggio di uscire dai bordi della finestra


    }
}



