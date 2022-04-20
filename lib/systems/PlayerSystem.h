#ifndef ENGINEJ_PLAYERSYSTEM_H
#define ENGINEJ_PLAYERSYSTEM_H

#include <SDL.h>
#include "System.h"
#include "../core/Entity.h"
#include "../components/Transform.h"

class PlayerSystem final : public System {
private:
    SDL_Event event;
    Transform *rootTransform;
    void handleKeyDown();
    void handleKeyUp();
public:
    explicit PlayerSystem(Entity *_root);
    void update() override;
    ~PlayerSystem() override = default;
};


#endif //ENGINEJ_PLAYERSYSTEM_H
