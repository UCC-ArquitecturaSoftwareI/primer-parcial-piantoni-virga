#include <raylib.h>
#include <vector>
#include <iostream>
#include "clases/bala.h"
#include "clases/Nave.h"



int main(){
    const int MAXDISPAROS=5;
    const int WindowWidth = 1280;
    const int WindowHeigh = 720;
    Nave* jugador;
    InitWindow(WindowWidth, WindowHeigh, "EL JUEGO");

    SetTargetFPS(60);
    float x = 32.0f, y=32.0f;

    //Inicializacion de disparos

    Bala disparo[MAXDISPAROS];
     jugador= new  Nave ( "resources/ship.png" , Vector2 {WindowWidth / 2 ,WindowHeigh - 45 });

    for (int i=0; i<MAXDISPAROS; i++) {

        disparo[i].position = jugador->getNavePos();
        disparo[i].radio = 10;
        disparo[i].color = WHITE;
        disparo[i].activo = false;
        disparo[i].Lifespown = 0;

    }


    while (!WindowShouldClose()){
        if ( IsKeyDown (KEY_RIGHT)) {
            jugador-> move_x ( 25.0f );


        }
        if ( IsKeyDown (KEY_LEFT)) {

            jugador-> move_x ( -25.0f );
        }




        BeginDrawing();

             ClearBackground(BLACK);



        //TRABAJO CON EL ESPACIO PARA CONFIGURAR LA BALA
            if (IsKeyPressed(KEY_SPACE))
            {
                for (int i = 0; i < MAXDISPAROS; i++){

                    if (!disparo[i].activo) {
                        disparo[i].position = jugador->getNavePos();

                        disparo[i].activo = true;
                        break;
                    }
                }
            }

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
                        disparo[i].position = jugador->getNavePos();
                        disparo[i].Lifespown = 0;
                        disparo[i].activo = false;

                    }

                }

            }



              static float rotation = 0.5f;
               rotation ++;
               DrawRectangle(x,y,100,300, RED);
               DrawRectangleV(Vector2{300,200}, Vector2{100,30}, BLACK);
               DrawRectanglePro(Rectangle{200,200,100,100}, Vector2{50,50}, rotation, GREEN);
             jugador->draw();
             DrawCircle(400,300,64, ORANGE);
             DrawTriangle(Vector2{50,0}, Vector2{0,100}, Vector2{100,100}, YELLOW);

             EndDrawing();


    }



}