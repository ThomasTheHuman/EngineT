#include "PlayerSystem.h"


void PlayerSystem::update() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_KEYDOWN:
            handleKeyDown();
            break;
        case SDL_KEYUP:
            handleKeyUp();
            break;
    }
}

void PlayerSystem::handleKeyUp() {
    switch (event.key.keysym.sym) {
    }
}

void PlayerSystem::handleKeyDown() {
    switch (event.key.keysym.sym) {
        case SDLK_UP:
            rootTransform->position += Vector3D(4, -4, 0);
            break;
        case SDLK_RIGHT:
            rootTransform->position += Vector3D(-4, -4, 0);
            break;
        case SDLK_DOWN:
            rootTransform->position += Vector3D(-4, 4, 0);
            break;
        case SDLK_LEFT:
            rootTransform->position += Vector3D(4, 4, 0);
            break;
    }
}

PlayerSystem::PlayerSystem(Entity *_root)
: System(_root), rootTransform(_root->getComponent<Transform>()), event() {

}
