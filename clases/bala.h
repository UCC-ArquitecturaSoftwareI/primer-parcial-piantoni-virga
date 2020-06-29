/**
 * @title       Clase bala
 * @file        bala.h
 * @version     1.0
 * @author      Francisco Piantoni Vera
 * @author      Santos Jose Virga
*/
#include <raylib.h>
#include <string>
#include <iostream>


#ifndef RAYLIBTEMPLATE_BALA_H
#define RAYLIBTEMPLATE_BALA_H


class Bala {


public:
    bool activo;
    Color color;
    Vector2 position;
    int VidaUtil;
    int damage;
    float radio;



};


#endif //RAYLIBTEMPLATE_BALA_H

