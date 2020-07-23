/**
* @title       Clase Nave
* @file        Nave.h
* @version     1.0
* @author      Francisco Piantoni Vera
* @author      Santos Jose Virga
*/


#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H


#include <raylib.h>
#include <string>
#include "rendering.h"
#include "torpedo.h"

class Nave {
private:
    double length;
    double width;
    float rot;
    int vida;

protected:
    std::string tNave;
    rendering &renderer=rendering::get();
public:
    Nave(std::string text, const Vector2 &navePos, float r);
    bool active;
    Rectangle jugador0Colision;
    Rectangle jugador1Colision;



    Nave(double, double);

    double getLength() const;

    double getWidth() const;

    void draw();

    void move_x(float d);

    void move_y(float d);

    int getVida() const;

    const Vector2 &getNavePos() const;

    Vector2 nave_pos;

    void disparar(std::list<torpedo> &disparos);
};


#endif //RAYLIBTEMPLATE_NAVE_H
