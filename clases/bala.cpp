//
// Created by santo on 25/4/2020.
//


#include <string>
#include "bala.h"


Bala::Bala(std::string text, const Vector2 &balaPos) : bala_pos(balaPos) {
    bala = LoadTexture(text.c_str());
}

void Bala::draw() {

    DrawTexture(bala , bala_pos.x - bala.width/2, bala_pos.y- bala.height/2, WHITE);
}

void Bala::move_x(float d) {
    bala_pos.x += d;
}
void Bala::move_y(float d) {
    bala_pos.y += d;
}

void Bala::setBalaPos(const Vector2 &balaPos) {
    bala_pos = balaPos;
}


