#include "CoreAPI.h"
#include "../core/GameController.h"
#include <memory>

std::unique_ptr<GameController> game;

void init() {
    game = std::make_unique<GameController>(
            "EngineT",
            0,
            0,
            2560/2,
            1600/2,
            true);
}

const int FPS = 120;
const int frameDelay = 1000 / FPS;

void run() {
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