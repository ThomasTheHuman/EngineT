#ifndef ENGINEJ_RENDERABLE_H
#define ENGINEJ_RENDERABLE_H


#include "Component.h"
#include <atomic>

struct Renderable : Component {
    std::atomic<bool> render = false;
    SDL_Texture* texture = nullptr;
    std::string spriteSheet;
    SDL_Rect srcRect {0,0,0,0};
};


#endif //ENGINEJ_RENDERABLE_H
