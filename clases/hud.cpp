//
// Created by Francisco Piantoni on 27/06/2020.
//
#include <string>
#include "hud.h"


Texture2D testing;

void menuInit(){
    testing=LoadTexture("resources/backgroundmenu.png" );
}

void menuDraw(){
    DrawRectangle( 0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    DrawText("START", static_cast<float>(GetScreenWidth()) - 450, static_cast<float>(GetScreenHeight()) - 350, 20, WHITE);
    DrawText("PRESS ESC TO CLOSE", static_cast<float>(GetScreenWidth()) - 450, static_cast<float>(GetScreenHeight()) - 300, 20, WHITE);
    DrawText("Made by Francisco Piantoni Vera & Santos Jose Virga", static_cast<float>(GetScreenWidth()) - 795, static_cast<float>(GetScreenHeight()) - 20, 10, WHITE);

}

