//
// Created by Francisco Piantoni on 29/05/2020.
//

#include <iostream>
#include <cmath>
#include "mapa.h"
using namespace std;


Mapa::Mapa(std::string file) {

    tson::Tileson parser;
    map = parser.parse(fs::path(file));

    if (map.getStatus() == tson::ParseStatus::OK) {

        for (auto &tileset : map.getTilesets()) {
            map_tex = LoadTexture(fs::path("resources/Map/" + tileset.getImage().string()).c_str());
            map_tileset = &tileset;

        }

        //Inicializamos el player, pasandolo con el nombre del primer objeto
        auto objs = map.getLayer("Objetos");
        tson::Object *player = objs->firstObj("player");
        player_init_pos.x = player->getPosition().x;
        player_init_pos.y = player->getPosition().y;
        std::cout << "Vida jugador 1: " << player->get<int>("Vida") << std::endl;


        //Inicializamos la posicion del enemigo, pasandolo por el id
        auto eobjs = map.getLayer( "Objetos");
        tson::Object *penemigo = eobjs->getObj(14);
        enemigo_init_pos.x = penemigo->getPosition().x;
        enemigo_init_pos.y = penemigo->getPosition().y;
        std::cout << "Vida jugador 2: " << penemigo->get<int>("Vida") << std::endl;




        for (auto &obj : objs->getObjects()) {
            //Just iterate through all the objects
            std::cout << "Nombre: " << obj.getName() << std::endl;
            std::cout << "Pos: " << obj.getPosition().x << std::endl;
        }
    }

}

void:: Mapa::dibujar() {
  Rectangle tile_rec;
    tile_rec.x = 0.0f;
    tile_rec.y = 0.0f;
    tile_rec.width = map.getTileSize().x;
    tile_rec.height = map.getTileSize().y;

    int firstId = map_tileset->getFirstgid();
    int columns = map_tileset->getColumns();
    int margin = map_tileset->getMargin();
    int space = map_tileset->getSpacing();


      auto &c = map.getBackgroundColor();
    ClearBackground({c.r, c.g, c.b, c.a}); //Limpio la pantalla en blanco

    for (auto nombre: {"Espacio"}) {
        auto *layer = map.getLayer(nombre);
        for (auto&[pos, tile] : layer->getTileData()) {

            if (tile != nullptr) {
                Vector2 position = {
                                    (float) std::get<0>(pos) * map.getTileSize().x,
                                    (float) std::get<1>(pos) * map.getTileSize().y};

                int baseTilePosition = (tile->getId() - firstId);

                int tileModx = (baseTilePosition % columns);
                int currentRow = (baseTilePosition / columns);
                int offsetX = tileModx * (map.getTileSize().x + space) + margin;
                int offsetY = currentRow * (map.getTileSize().y + space) + margin;

                tile_rec.x = offsetX;
                tile_rec.y = offsetY;
                DrawTextureRec(map_tex, tile_rec, position, WHITE);
            }
        }

    }
}

