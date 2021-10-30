#include "CoreAPI.h"
#include "../core/GameController.h"
#include <memory>
#include "../core/Map.h"

std::unique_ptr<GameController> game;

void init() {
    game = std::make_unique<GameController>(
            "EngineT",
            0,
            0,
            2560/3,
            1600/3,
            false);
}

void run() {
    const int FPS = 120;

    const int frameDelay = 1000 / FPS;

    int renderFrame = true;
    while (game->running()) {
        const Uint32 frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        if (renderFrame) {
            game->render();
            renderFrame = false;
        } else {
            renderFrame = true;
        }

        const Uint32 frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}