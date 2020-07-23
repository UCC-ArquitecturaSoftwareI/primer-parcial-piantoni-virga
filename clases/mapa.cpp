//
// Created by Francisco Piantoni on 29/05/2020.
//
#include "mapa.h"

Texture2D mapTexture;
Rectangle mapRec;
void mapInit()
{
    mapRec = {0,0,800, 450};
    mapTexture = LoadTexture("resources/Map/mapa.png");
}
/**
 *  Dibuja el Mapa
 */
void mapDraw()
{
    DrawTexture(mapTexture, 0,0 ,WHITE);
}

void mapUnload()
{
    UnloadTexture(mapTexture);
}
