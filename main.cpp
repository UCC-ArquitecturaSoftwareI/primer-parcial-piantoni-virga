#include <raylib.h>
#include <vector>


#include "clases/Nave.h"
#include "clases/bala.h"


#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const float screenWidth = 800;
const float screenHeight = 450;

// Variables Globales
Music music;
Nave *player;
Bala *disparo;

static void UpdateDrawFrame(void);          // Función dedicada a operar cada frame

int main() {
    int c;
    c = 10; //cantidad de disparos
    // Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib template - advance game");
    InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");

    PlayMusicStream(music);
    player = new Nave("resources/ship.png", Vector2{screenWidth / 2, screenHeight - 45});
    disparo = new Bala("resources/ship.png", Vector2{screenWidth / 2, screenHeight - 45});


#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif


    // Descargar todos los resources cargados

    UnloadMusicStream(music);   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
    return 0;
}


/**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
static void UpdateDrawFrame(void) {

    static std::vector<Bala *> conjuntoDeBalas;

    // siempre hay que reproducir la musica que esta actualmente
    // UpdateMusicStream(music);

    // Verifico Entradas de eventos.
    if (IsKeyDown(KEY_RIGHT)) {
        player->move_x(25.0f);
        disparo->move_x(25.0f);

    }
    if (IsKeyDown(KEY_LEFT)) {
        disparo->move_x(-25.0f);
        player->move_x(-25.0f);
    }


    if (IsKeyDown(KEY_SPACE)) {
        Bala *bali = new Bala("resources/ship.png", player->getNavePos());
        conjuntoDeBalas.push_back(bali);
    }

    if (IsKeyDown(KEY_ESCAPE)) {
        EndDrawing();
    };

    // Verificaciones

    //disparo->draw();
    for (auto it = conjuntoDeBalas.begin(); it != conjuntoDeBalas.end(); it++) {
        (*it)->move_y(-10.0f);
        if ((*it)->getBalaPos().y <= 0) {
            delete (*it);
            conjuntoDeBalas.erase(it);
        }
    }

    if(player->getNavePos().x > screenWidth){
       // player->setNavePos().x = screenWidth;
    }


    // Comienzo a dibujar
    BeginDrawing();


    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

    //disparo->draw();
    for (auto b: conjuntoDeBalas) {
        b->draw();
    }

    // Dibujo todos los elementos del juego.

    player->draw();

    DrawText("ESCAPE PARA SALIR ", 20, 20, 40, LIGHTGRAY);

    // Finalizo el dibujado
    EndDrawing();
}