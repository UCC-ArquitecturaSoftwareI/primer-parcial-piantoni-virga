//
// Created by Francisco Piantoni on 17/07/2020.
//

#include <list>
#include "gameplayScreen.h"
#include "Nave.h"
#include "torpedo.h"
#include "hud.h"
#include "mapa.h"
#include "random"
#include "rendering.h"
#include "GameSettings.h"
rendering &renderer=rendering::get();
GameSettings* GameSettings::_instance = nullptr;

GameSettings *settings = GameSettings::getInstance();

//Mapa *map;

Nave jugador1( "resources/ship.png", {400, 40}, 180 );
Nave jugador2( "resources/Images/Enemigo.png", {400, 400}, 0 );
Nave pnave(86.0, 60.0);
Nave pnave1(86.0, 60.0);

std::list<torpedo> balas;

void InitGameplayScreen() {
    framesCounter = 0;
    finishScreen = 0;
    menuInit();
    mapInit();
    //map = new Mapa("../resources/Map/mapa.json");

    settings->getInstance();

}
/**
 *  Loop de Lógica del Juego
 */
void UpdateGameplayScreen() {
    if( settings->getisPlayerinMenu()== 0 )
    {
        if(jugador1.getVida()==0 || jugador2.getVida() == 0)
            std::cout<< " GANASTE EL JUEGO CONCHETUMARE "<< std::endl;
    }
    else if( settings->getisPlayerinMenu() == 1 )
    {
        //std::cout<<GetMousePosition().x<<" , "<<GetMousePosition().y<<std::endl;
        if (IsKeyPressed(KEY_SPACE)) {
            settings->SetisPlayerinMenu(0);
        }

        if (IsKeyPressed(KEY_ESCAPE))
            CloseWindow();
    }

    for (auto i = balas.begin(); i != balas.end(); ++i) {
        /*if (!i->getActivo()) {
            balas.erase(i);
        }*/
        i->move();
    }
    if (settings->getisPlayerinMenu() == 0) {
        // Movimiento del jugador1 con sus respectivas teclas.
        if (IsKeyDown(KEY_RIGHT)) { jugador1.move_x(5.0f); }
        if (IsKeyDown(KEY_LEFT)) { jugador1.move_x(-5.0f); }

        // Movimento del jugador2 con sus respectivas teclas.
        if (IsKeyDown(KEY_S)) { jugador2.move_x(5.0f); }
        if (IsKeyDown(KEY_A)) { jugador2.move_x(-5.0f); }

        if (IsKeyPressed(KEY_M)) {
            for (int i = 0; i < settings->getMAXDISPAROSRED(); i++) {
                jugador2.disparar(balas);
/*
                if (CheckCollisionCircleRec(disparo[i].position, disparo[i].radio, penemigo->jugador1Colision)) {

                    penemigo->vida = ((penemigo->vida) - (disparo->damage));
                    if (penemigo->vida == 0) {
                        std::cout << "Fin de la Ronda, Gana jugador 0" << std::endl;
                        player->vida = 1000;
                        penemigo->vida += 1000;
                    }
                    std::cout << "Jugador 1 Alcanzado  " << std::endl;
                    disparo[i].VidaUtil = 0;
                    disparo[i].activo = false;
                }
*/
            }
        }
        jugador1.jugador1Colision.x = jugador1.nave_pos.x - ((pnave1.getWidth()) / 2);
        jugador1.jugador1Colision.y = jugador1.nave_pos.y;
        jugador1.jugador1Colision.width = pnave1.getWidth();

    }
    //TRABAJO CON EL ESPACIO PARA CONFIGURAR LA BALA DEL JUGADOR 1
    if (IsKeyPressed(KEY_D)) {
        for (int i = 0; i < settings->getMAXDISPAROSBLUE(); i++) {
            jugador1.disparar(balas);
/*
            if (CheckCollisionCircleRec(balas[i].position, disparo[i].radio, penemigo->jugador1Colision)) {

                jugador2->vida = ((jugador2->vida) - (jugador2->damage));
                if (jugador2->vida == 0) {
                    std::cout << "Fin de la Ronda, Gana jugador 0" << std::endl;
                    jugador1->vida = 1000;
                    jugador2->vida += 1000;
                }
                std::cout << "Jugador 1 Alcanzado  " << std::endl;
                disparo[i].VidaUtil = 0;
                disparo[i].activo = false;
            }
            */
        }
    }
    jugador2.jugador0Colision.x = jugador2.nave_pos.x - ((pnave.getWidth()) / 2);
    jugador2.jugador0Colision.y = jugador2.nave_pos.y;
    jugador2.jugador0Colision.width = pnave1.getWidth();





    if ((jugador1.nave_pos.x + pnave.getWidth()) >= GetScreenWidth())
        jugador1.nave_pos.x = GetScreenWidth() - pnave.getWidth();
    else if (jugador1.nave_pos.x <= 110) jugador1.nave_pos.x = 110;

    if ((jugador2.nave_pos.x + pnave1.getWidth()) >= GetScreenWidth())
        jugador2.nave_pos.x = GetScreenWidth() - pnave1.getWidth();
    else if (jugador2.nave_pos.x <= 100)
        jugador2.nave_pos.x = 100;
    framesCounter++;
}


/**
 *  Loop de Dibujo del Juego
 */
void DrawGameplayScreen() {
    if( settings->getisPlayerinMenu() == 0 ) {
        mapDraw();
        //map.dibujar();
        jugador1.draw();
        jugador2.draw();
        for (auto i = balas.begin(); i != balas.end(); ++i) {
            i->draw();
        }
    } else if( settings->getisPlayerinMenu() == 1){
        menuDraw();
    }
}

void UnloadGameplayScreen() {

}

int FinishGameplayScreen() {
    return finishScreen;
}
