//
// Created by Francisco Piantoni on 17/07/2020.
//


#ifndef RAYLIBTEMPLATE_RENDERING_H
#define RAYLIBTEMPLATE_RENDERING_H


#include <list>
#include <iostream>
#include "raylib.h"
#include <map>
#include <unordered_map>
#include <math.h>

class rendering {
private:
    rendering(){}


    int currentframe = 0;
    std::unordered_map<std::string, Texture2D> textMap;

    Texture2D &getTexture(std::string s)  //Flyweight para pasar las texturas dentro del Renderer
    {
        auto myText=textMap.find(s);
        if (myText==textMap.end())
        {

            textMap.emplace(s,LoadTexture(s.c_str()));
        }

        return textMap[s];

    }
public:

    static rendering &get()  //Singleton para tener un solo renderer global.
    {
        static rendering renderer;
        return renderer;
    }
    /**
 *  Función dedicada a dibujar cada enemigo. Se le deben pasar el path a la textura, las coordenadas x e y, y la rotacion.
 */

    void drawNave(std::string a, float x, float y, float rot) {
        //DrawTextureEx(getTexture(a), {x - getTexture(a).width / 2, y - getTexture(a).height / 2}, rot, 1, WHITE);
        DrawTexturePro(getTexture(a),
                       {0,0,static_cast<float>(getTexture(a).width),static_cast<float>(getTexture(a).height)},
                       {x ,y,64,64},
                       {32,32},rot,WHITE);
    }
    /**
 *  Función dedicada a dibujar un proyectil
 *  Se le deben pasar el path a la textura, las coordenadas x e y, y la rotacion del misil.
 */
    void drawTorpedo( float x, float y ) {
        DrawCircleV( {x, y}, 10, RED);
    }
};


#endif //RAYLIBTEMPLATE_RENDERING_H
