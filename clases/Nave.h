 //
// Created by martin on 21/3/20.
//
#include <raylib.h>
#include <string>
#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H


 class Nave {

    /**/
 private:
    double length;
    double width;


 protected:
     Texture2D nave;


 public:
     Nave(std::string text,const Vector2 &navePos);

    /**/
    Nave (double, double);
    double getLength() const;
    double getWidth() const;


     void draw();
     void move_x(float d);
     void move_y(float d);

     const Vector2 &getNavePos() const;

     Vector2 nave_pos;
 };
    /**/
    Nave::Nave(double l , double w=0) {
        length = l;
        width = w;
    }

 double Nave::getWidth() const { return width; }
 double Nave::getLength() const { return length; }


#endif //RAYLIBTEMPLATE_NAVE_H