#ifndef ENGINEJ_RENDERSYSTEM_H
#define ENGINEJ_RENDERSYSTEM_H


#include <SDL.h>
#include "System.h"
#include "../core/Entity.h"
#include "../components/Renderable.h"
#include "../core/Vector3D.h"
#include "../components/Terrain.h"
#include <mutex>
#include <vector>
#include <array>

class RenderSystem final : public System {
private:
    static std::mutex poolMutex;
    static std::array<std::vector<Renderable*>, MAX_ENTITY_LAYERS> *renderPool;
    SDL_Renderer* renderer{};
    SDL_Window* window{};

    [[noreturn]] static void poolingThread(Entity *_root);
    static void poolEntity(Entity &entity, std::array<std::vector<Renderable*>, MAX_ENTITY_LAYERS> *pool, int g);
    static void calcAbsolute(const Entity *entity, Vector3D &absolutePosition);
    void loadRenderable(Renderable *renderable);
    void renderChunk(const Vector3D *origin, Terrain *terrain, int x, int y);
    void renderEntities();
public:
    explicit RenderSystem(Entity *_root);
    void update() override;
    ~RenderSystem() override = default;
};


#endif //ENGINEJ_RENDERSYSTEM_H
