//
// Created by martin on 21/3/20.
//

#include <string>
#include "Enemigo.h"

Enemigo::Enemigo(std::string text, const Vector2 &navePos) : nave_pos(navePos) {

    nave = LoadTexture(text.c_str());
}

Enemigo::Enemigo(double l , double w) {
    length = l;
    width = w;
}

void Enemigo::draw() {

    DrawTexture(nave, nave_pos.x - nave.width/2, nave_pos.y- nave.height/2, WHITE);
}

void Enemigo::move_x(float d) {
    nave_pos.x += d;
}
void Enemigo::move_y(float d) {
    nave_pos.y += d;
}

const Vector2 &Enemigo::getNavePos() const {
    return nave_pos;
}

double Enemigo::getWidth() const {
    return width;
}

double Enemigo::getLength() const {
    return length; }




