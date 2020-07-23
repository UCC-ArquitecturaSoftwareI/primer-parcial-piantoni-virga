/**
 * @title       Clase bala
 * @file        bala.h
 * @version     1.0
 * @author      Francisco Piantoni Vera
 * @author      Santos Jose Virga
*/



#ifndef RAYLIBTEMPLATE_TORPEDO_H
#define RAYLIBTEMPLATE_TORPEDO_H

#include <raylib.h>
#include <string>
#include <iostream>
#include "rendering.h"
#include "Nave.h"

class torpedo {
private:
    bool activo;
    Vector2 position;
    int VidaUtil;
    int damage;
    float radio;
    rendering &renderer = rendering::get();
public:

    /**
 *  Constructor de Projectile
 */
    torpedo( Vector2 p );

    void move();
    const Vector2 &getPos() const;
    void draw();
    bool getActivo(){
        return activo;
    }
};

#endif //RAYLIBTEMPLATE_TORPEDO_H

