//
// Created by santo on 25/4/2020.
//
#include <raylib.h>
#include <string>
#include <iostream>


#ifndef RAYLIBTEMPLATE_BALA_H
#define RAYLIBTEMPLATE_BALA_H



class Bala {

    Texture2D bala;
    Vector2 bala_pos;


public:
    Bala(std::string text,  const Vector2 &balaPos) ;

    void draw();
    void move_x(float d);
    void move_y(float d);
    void setBalaPos(const Vector2 &balaPos);
    void EliminarBala(const float a , const float b);

};


#endif //RAYLIBTEMPLATE_BALA_H
