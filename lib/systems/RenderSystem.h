#ifndef ENGINEJ_RENDERSYSTEM_H
#define ENGINEJ_RENDERSYSTEM_H


#include <SDL.h>
#include "System.h"
#include "../core/Entity.h"
#include "../components/Renderable.h"
#include "../core/Vector3D.h"
#include <mutex>
#include <vector>
#include <array>

class RenderSystem final : public System {
private:
    static std::mutex poolMutex;
    static std::array<std::vector<Renderable*>, 16> *renderPool;
    SDL_Renderer* renderer{};
    SDL_Window* window{};

    [[noreturn]] static void poolingThread(Entity *_root);
    static void poolEntity(Entity &entity, std::array<std::vector<Renderable*>, 16> *pool, int g);
    static void calcAbsolute(const Entity *entity, Vector3D &absolutePosition);
public:
    explicit RenderSystem(Entity *_root);
    void update() override;
    ~RenderSystem() override = default;
};


#endif //ENGINEJ_RENDERSYSTEM_H
