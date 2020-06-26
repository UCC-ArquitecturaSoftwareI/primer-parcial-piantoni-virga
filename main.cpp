#include <raylib.h>
#include <vector>
#include <iostream>
#include "clases/bala.h"
#include "clases/Nave.h"
#include "clases/mapa.h"
#include "clases/Enemigo.h"




//Variables globales
Mapa *mapa;
Nave *player;
Enemigo *penemigo;




int main(){
    const int MAXDISPAROSRED=4;
    const int MAXDISPAROSBLUE=4;
    const int WindowWidth = 820;
    const int WindowHeigh = 840;
    //Nave* jugador;
    InitWindow(WindowWidth, WindowHeigh, "EL JUEGO");

    SetTargetFPS(60);
    float x = 32.0f, y=32.0f;

    mapa = new Mapa ("../resources/Map/mapa.json");

    player = new Nave ("resources/ship.png", mapa->player_init_pos);

    penemigo = new Enemigo ("resources/Images/Enemigo.png", mapa->enemigo_init_pos);

    //Tamaño del jugador 1
    Nave pnave(86.0, 78.0);

    //Tamaño del jugador 2
    Enemigo pnave1(86.0, 78.0);




    //Inicializacion de disparos

    Bala disparo[MAXDISPAROSRED];
    Bala disparo1[MAXDISPAROSBLUE];


    for (int i=0; i<MAXDISPAROSRED; i++) {

        //Disparos del Jugador numero 0
        disparo[i].position = player->getNavePos();
        disparo1[i].position = penemigo->getEnemigoPos();
        disparo[i].radio = 10;
        disparo[i].color = RED;
        disparo[i].activo = false;
        disparo[i].Lifespown = 0;
        disparo[i].damage = 100;

        // Disparos del jugadores numero 1
        disparo1[i].radio = 10;
        disparo1[i].color = BLUE;
        disparo1[i].activo = false;
        disparo1[i].Lifespown = 0;

    }

    for (int i=0; i<MAXDISPAROSBLUE; i++) {

        // Disparos del jugadores numero 1
        disparo1[i].position = penemigo->getEnemigoPos();
        disparo1[i].radio = 10;
        disparo1[i].color = BLUE;
        disparo1[i].activo = false;
        disparo1[i].Lifespown = 0;
        disparo1[i].damage = 100;

    }

    while (!WindowShouldClose()){

        // Movimiento del jugador1 con sus respectivas teclas.
        if ( IsKeyDown (KEY_RIGHT)) {
            player-> move_x ( 5.0f );


        }
        if ( IsKeyDown (KEY_LEFT)) {

            player-> move_x ( -5.0f );
        }

        // Movimento del jugador2 con sus respectivas teclas.
            if (IsKeyDown(KEY_S)) {
                penemigo->move_x(5.0f);


            }
            if (IsKeyDown(KEY_A)) {

                penemigo->move_x(-5.0f);
            }




        BeginDrawing();
        mapa->dibujar();
        player->draw();
        penemigo->draw();

        //ClearBackground(BLACK);



        //TRABAJO CON EL ESPACIO PARA CONFIGURAR LA BALA DEL JUGADOR 0
            if (IsKeyPressed(KEY_SPACE))
            {
                for (int i = 0; i < MAXDISPAROSRED; i++){

                    if (!disparo[i].activo) {
                        disparo[i].position = player->getNavePos();

                        disparo[i].activo = true;
                        break;
                    }
                }
            }

        //TRABAJO CON EL ESPACIO PARA CONFIGURAR LA BALA DEL JUGADOR 1
            if (IsKeyPressed(KEY_D))
            {
                for (int i = 0; i < MAXDISPAROSBLUE; i++){

                    if (!disparo1[i].activo) {
                        disparo1[i].position = penemigo->getEnemigoPos();

                        disparo1[i].activo = true;
                        break;
                    }
                }
            }



        /*
          LIMITES DE LOS JUGADORES AL MOVERSE HACIA LOS BORDES.
        */
            if ((player->nave_pos.x +  pnave.getWidth()) >= GetScreenWidth()) player->nave_pos.x = GetScreenWidth() -  pnave.getWidth();
            else if (player->nave_pos.x <= 110) player->nave_pos.x=110;

            if ((penemigo->enemigo_pos.x +  pnave1.getWidth()) >= GetScreenWidth()) penemigo->enemigo_pos.x = GetScreenWidth() -  pnave1.getWidth();
            else if (penemigo->enemigo_pos.x <= 100) penemigo->enemigo_pos.x=100;



        // "FOR"para todas las intrucciones que tiene que realizar la bala del jugador 0.
            for (int i=0; i<MAXDISPAROSRED; i++) {
                if (disparo[i].activo) {
                    disparo[i].position.y -= 10;    //Esta linea nos dice la direccion de la bala, en conjkunto para los dos jugadores

                    disparo[i].Lifespown++;

                    penemigo->jugador1Colision.x = penemigo->enemigo_pos.x;
                    penemigo->jugador1Colision.y = penemigo->enemigo_pos.y;
                    penemigo->jugador1Colision.width = penemigo->getWidth();

                    if (disparo[i].position.y > 800) {
                        disparo[i].activo = false;
                    }

                    if (disparo[i].activo) {
                        DrawCircleV(disparo[i].position, disparo[i].radio, RED);

                    }

                    //cuan lejos puede llegar la bala hasta ser desactivada

                    if (disparo[i].Lifespown >= 80) {
                        disparo[i].position = player->getNavePos();
                        disparo[i].Lifespown = 0;
                        disparo[i].activo = false;

                    }

                    if (CheckCollisionCircleRec(disparo[i].position, disparo[i].radio, penemigo->jugador1Colision)) {

                        //penemigo->vida = ((penemigo->vida) - (disparo->damage));
                        std::cout<<"Jugador 1 Alcanzado:  " << std::endl;
                        disparo[i].Lifespown = 0;
                        disparo[i].activo = false;
                    }

                }

            }

        // "FOR" para todas las intrucciones que tiene que realizar la bala del jugador 1.
            for (int i=0; i<MAXDISPAROSBLUE; i++) {
                if (disparo1[i].activo) {
                    disparo1[i].position.y += 10;    //Esta linea nos dice la direccion de la bala, en conjkunto para los dos jugadores

                    disparo1[i].Lifespown++;

                    player->jugador0Colision.x = player->nave_pos.x;
                    player->jugador0Colision.y = player->nave_pos.y;
                    player->jugador0Colision.width = player->getWidth();


                    if (disparo1[i].position.y < 0) {
                        disparo1[i].activo = false;
                    }

                    if (disparo1[i].activo) {
                        DrawCircleV(disparo1[i].position, disparo1[i].radio, BLUE);

                    }

                    //cuan lejos puede llegar la bala hasta ser desactivada

                    if (disparo1[i].Lifespown >= 80) {
                        disparo1[i].position = penemigo->getEnemigoPos();
                        disparo1[i].Lifespown = 0;
                        disparo1[i].activo = false;

                    }

                    if (CheckCollisionCircleRec(disparo1[i].position, disparo1[i].radio, player->jugador0Colision)) {

                        //player->vida = ((player->vida) - (disparo->damage));
                        std::cout<<"Jugador 0 Alcanzado:  " << std::endl;
                        disparo1[i].Lifespown = 0;
                        disparo1[i].activo = false;
                    }

                }

            }





              static float rotation = 0.5f;
               rotation ++;

             EndDrawing();


    }



}