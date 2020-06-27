//
// Created by santo on 25/4/2020.
//
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
    int Lifespown;
    int damage;
    float radio;

    void moveposition();

    void acelerar();


};


#endif //RAYLIBTEMPLATE_BALA_H


/*void move_x(float d);
void move_y(float d);
void setBalaPos(const Vector2 &balaPos);
void EliminarBala(const float a , const float b);

const Vector2 &getBalaPos() const;*/