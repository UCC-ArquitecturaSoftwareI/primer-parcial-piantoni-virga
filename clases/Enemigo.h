//
// Created by martin on 21/3/20.
//
#include <raylib.h>
#include <string>
#ifndef RAYLIBTEMPLATE_ENEMIGO_H
#define RAYLIBTEMPLATE_ENEMIGO_H


 class Enemigo {

    /**/
 private:
    double length;
    double width;


 protected:
     Texture2D nave;


 public:
     Enemigo(std::string text,const Vector2 &navePos);

    /**/
    Enemigo (double, double);
    double getLength() const;
    double getWidth() const;


     void draw();
     void move_x(float d);
     void move_y(float d);

     const Vector2 &getNavePos() const;

     Vector2 nave_pos;

 };




#endif //RAYLIBTEMPLATE_NAVE_H