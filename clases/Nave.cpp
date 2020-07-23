//
// Created by Francisco Piantoni on 17/07/2020.
//

#include <string>
#include <utility>
#include "Nave.h"
#include "torpedo.h"


Nave::Nave(std::string text, const Vector2 &navePos, float r) : nave_pos(navePos) {
    rot=r;
    tNave = std::move(text);
    vida = 1000;
}

Nave::Nave(double l, double w) {
    length = l;
    width = w;
}


void Nave::draw() {
    renderer.drawNave(this->tNave, this->nave_pos.x - this->width / 2, this->nave_pos.y - this->length, this->rot );
}

void Nave::move_x(float d) {
    nave_pos.x += d;
}


void Nave::move_y(float d) {
    nave_pos.y += d;
}

const Vector2 &Nave::getNavePos() const {
    return nave_pos;
}

double Nave::getWidth() const {
    return width;
}

double Nave::getLength() const {
    return length;
}

int Nave::getVida() const{
    return vida;
}

void Nave::disparar(std::list<torpedo> &disparos) {
    disparos.emplace_back(this->nave_pos);
}




