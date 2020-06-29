/**
 * @title       Clase Enemigo
 * @file        Enemigo.h
 * @version     1.0
 * @author      Francisco Piantoni Vera
 * @author      Santos Jose Virga
*/
#include <raylib.h>
#include <string>

#ifndef RAYLIBTEMPLATE_ENEMIGO_H
#define RAYLIBTEMPLATE_ENEMIGO_H


class Enemigo {


private:

    double length;
    double width;


protected:
    Texture2D enemigo;


public:
    Enemigo(std::string text, const Vector2 &enemigoPos);

    int vida = 1000;
    bool active;
    Rectangle jugador1Colision;

    Enemigo(double, double);

    double getLength() const;

    double getWidth() const;


    void draw();

    void move_x(float d);

    void move_y(float d);

    const Vector2 &getEnemigoPos() const;

    Vector2 enemigo_pos;

};


#endif //RAYLIBTEMPLATE_ENEMIGO_H