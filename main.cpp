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
    const int MAXDISPAROS=5;
    const int WindowWidth = 820;
    const int WindowHeigh = 840;
    //Nave* jugador;
    InitWindow(WindowWidth, WindowHeigh, "EL JUEGO");

    SetTargetFPS(60);
    float x = 32.0f, y=32.0f;

    mapa = new Mapa ("../resources/Map/mapa.json");

    player = new Nave ("resources/ship.png", mapa->player_init_pos);

    penemigo = new Enemigo ("resources/Images/Enemigo.png", mapa->enemigo_init_pos);

    //Tamaño de la nave, insertar tamaño de la nave enemiga en caso de que se mueva.
    Nave pnave(86.0, 78.0);



    //Inicializacion de disparos

    Bala disparo[MAXDISPAROS];


    for (int i=0; i<MAXDISPAROS; i++) {

        disparo[i].position = player->getNavePos();
        disparo[i].radio = 10;
        disparo[i].color = WHITE;
        disparo[i].activo = false;
        disparo[i].Lifespown = 0;

    }


    while (!WindowShouldClose()){
        if ( IsKeyDown (KEY_RIGHT)) {
            player-> move_x ( 5.0f );


        }
        if ( IsKeyDown (KEY_LEFT)) {

            player-> move_x ( -5.0f );
        }




        BeginDrawing();

        mapa->dibujar();
        player->draw();
        penemigo->draw();

        //ClearBackground(BLACK);



        //TRABAJO CON EL ESPACIO PARA CONFIGURAR LA BALA
            if (IsKeyPressed(KEY_SPACE))
            {
                for (int i = 0; i < MAXDISPAROS; i++){

                    if (!disparo[i].activo) {
                        disparo[i].position = player->getNavePos();

                        disparo[i].activo = true;
                        break;
                    }
                }
            }




        /*
         * LIMITES DE LA NAVE AL MOBVERSE HACIA LOS BORDES.
        */
            if ((player->nave_pos.x +  pnave.getWidth()) >= GetScreenWidth()) player->nave_pos.x = GetScreenWidth() -  pnave.getWidth();
            else if (player->nave_pos.x <= 70) player->nave_pos.x=70;



        // Otro "for" para todas las cosas que tenga que hacer la bala cuando activo = true;
            for (int i=0; i<MAXDISPAROS; i++) {
                if (disparo[i].activo) {
                    disparo[i].position.y -= 10;

                    disparo[i].Lifespown++;

                    if (disparo[i].position.y > 800) {
                        disparo[i].activo = false;
                    }

                    if (disparo[i].activo) {
                        DrawCircleV(disparo[i].position, disparo[i].radio, WHITE);

                    }

                    //cuan lejos puede llegar la bala hasta ser desactivada

                    if (disparo[i].Lifespown >= 80) {
                        disparo[i].position = player->getNavePos();
                        disparo[i].Lifespown = 0;
                        disparo[i].activo = false;

                    }

                }

            }



              static float rotation = 0.5f;
               rotation ++;

             EndDrawing();


    }



}