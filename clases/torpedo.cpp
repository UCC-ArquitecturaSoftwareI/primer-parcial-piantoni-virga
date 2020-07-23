//
// Created by santos on 25/4/2020.
//



#include "WindowController.h"

torpedo::torpedo( Vector2 p ) {
    radio=10;
    position=p;
    damage=100;
    VidaUtil=0;
    activo=true;
}

void torpedo::move() {
    if (this->activo) {
        this->position.y -= 10;
        this->VidaUtil = VidaUtil+1;
/**
        penemigo->jugador1Colision.x = penemigo->enemigo_pos.x - ((pnave1.getWidth()) / 2);
        penemigo->jugador1Colision.y = penemigo->enemigo_pos.y;
        penemigo->jugador1Colision.width = pnave1.getWidth();
**/

        if (this->position.y > 800) {
            this->activo = false;
        }
        //cuan lejos puede llegar la bala hasta ser desactivada

        if (this->VidaUtil >= 80) {
            this->VidaUtil = 0;
            this->activo = false;
        }

        /**if (CheckCollisionCircleRec(this->position, this->radio, ->jugador1Colision)) {

            penemigo->vida = ((penemigo->vida) - (disparo->damage));
            if (penemigo->vida == 0) {
                std::cout << "Fin de la Ronda, Gana jugador 0" << std::endl;
                player->vida = 1000;
                penemigo->vida += 1000;
            }
            std::cout << "Jugador 1 Alcanzado  " << std::endl;
            disparo[i].VidaUtil = 0;
            disparo[i].activo = false;
        }**/

    }
}

void torpedo::draw() {
    renderer.drawTorpedo( position.x, position.y );
}

const Vector2 &torpedo::getPos() const {
    return position;
}



