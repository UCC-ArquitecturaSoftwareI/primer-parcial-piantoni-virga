//
// Created by martin on 21/3/20.
//
#include <raylib.h>
#include <string>
#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H


class Nave {

protected:
    Texture2D nave;
    Vector2 nave_pos;

public:
    Nave(std::string text,const Vector2 &navePos);

    void draw();
    void move_x(float d);
    void move_y(float d);

    const Vector2 &getNavePos() const;
};


#endif //RAYLIBTEMPLATE_NAVE_H
