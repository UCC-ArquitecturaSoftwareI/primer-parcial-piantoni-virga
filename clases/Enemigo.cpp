//
// Created by martin on 21/3/20.
//

#include <string>
#include "Enemigo.h"

Enemigo::Enemigo(std::string text, const Vector2 &enemigoPos) : enemigo_pos(enemigoPos) {

    enemigo = LoadTexture(text.c_str());
}


Enemigo::Enemigo(double l , double w) {
    length = l;
    width = w;
}



void Enemigo::draw() {

    DrawTexture(enemigo, enemigo_pos.x - enemigo.width/2, enemigo_pos.y- enemigo.height/2, WHITE);
}

void Enemigo::move_x(float d) {
    enemigo_pos.x += d;
}
void Enemigo::move_y(float d) {
    enemigo_pos.y += d;
}

const Vector2 &Enemigo::getEnemigoPos() const {
    return enemigo_pos;
}

double Enemigo::getWidth() const {
    return width;
}

double Enemigo::getLength() const {
    return length;
}




