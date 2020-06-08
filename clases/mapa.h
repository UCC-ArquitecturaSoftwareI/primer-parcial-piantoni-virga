//
// Created by Francisco Piantoni on 29/05/2020.
//

#ifndef RAYLIBTEMPLATE_MAPA_H
#define RAYLIBTEMPLATE_MAPA_H


#include <string>
#include <raylib.h>
#include "../libs/tileson.hpp"

class Mapa {
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;

public:
    Vector2 player_init_pos;

    Mapa(std::string file);

    void dibujar();

    //Vector2 &enemigo_init_pos;
    const Vector2 &enemigo_init_pos;
};

#endif //RAYLIBTEMPLATE_MAPA_H
