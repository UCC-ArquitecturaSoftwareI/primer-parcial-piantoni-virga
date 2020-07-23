//
// Created by Francisco Piantoni on 17/07/2020.
//


#ifndef RAYLIBTEMPLATE_WINDOWCONTROLLER_H
#define RAYLIBTEMPLATE_WINDOWCONTROLLER_H

#include <raylib.h>
#include "Nave.h"

#include "gameplayScreen.h"
const int screenWidth = 800;
const int screenHeight = 450;

class windowcontroller{
public:
    void start();
    static void UpdateDrawFrame();
};

#endif //RAYLIBTEMPLATE_WINDOWCONTROLLER_H
