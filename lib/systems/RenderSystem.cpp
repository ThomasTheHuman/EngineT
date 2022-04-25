#include "RenderSystem.h"
#include "../components/Transform.h"
#include <algorithm>
#include <thread>
#include <chrono>
#include <cmath>

std::mutex RenderSystem::poolMutex = std::mutex();
std::array<std::vector<Renderable*>, MAX_ENTITY_LAYERS> *RenderSystem::renderPool;

void RenderSystem::calcAbsolute(const Entity *entity, Vector3D &absolutePosition) {
    absolutePosition += entity->getComponent<Transform>()->position;
    if (!entity->root) {
        calcAbsolute(entity->parent, absolutePosition);
    }
}

void RenderSystem::update() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    auto origin = &root->getComponent<Transform>()->position;
    auto terrain = root->getComponent<Terrain>();
    auto floorX = -(int)floor(origin->x/(float)CHUNK_WIDTH);
    auto floorY = -(int)floor(origin->y/(float)CHUNK_WIDTH);

    for (int i = -2; i < 2; i++) {
        for (int j = 1; j > -3; j--) {
            renderChunk(origin, terrain, floorX + i, floorY + j);
        }
    }

    if (renderPool != nullptr) {
        poolMutex.lock();
        renderEntities();
        poolMutex.unlock();
    }
    SDL_RenderPresent(renderer);
}

void RenderSystem::renderEntities() {
    std::for_each(renderPool->begin(), renderPool->end(),
                  [this](std::vector<Renderable*> group) -> void {
        // TODO sort by position
        std::for_each(group.begin(), group.end(), [this](Renderable *renderable) -> void {
            auto entity = renderable->entity;
            auto absolute = Vector3D();
            calcAbsolute(entity, absolute);
            auto absolute2D = absolute.to2D();

            loadRenderable(renderable);
            SDL_Rect *srcRect = &renderable->srcRect;
            SDL_Rect destRect {(int)absolute2D.x, (int)absolute2D.y,
                               srcRect->w, srcRect->h};
            SDL_RenderCopyEx(
                    renderer,
                    renderable->texture,
                    srcRect,
                    &destRect,
                    0,
                    nullptr,
                    SDL_FLIP_NONE);
        });
    });
}

void RenderSystem::renderChunk(const Vector3D *origin, Terrain *terrain, int x, int y) {
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
        auto offsetX = origin->x + (float)(x * CHUNK_WIDTH);
        auto offsetY = origin->y + (float)(y * CHUNK_WIDTH);
        auto tiles = terrain->chunks[x][y].tiles;
        for (int i = 0; i < CHUNK_SIZE; i++) {
            for (int j = CHUNK_SIZE - 1; j >= 0; j--) {
                auto tile = tiles[i][j];
                auto coords = Vector3D(i*TILE_SIZE + offsetX, j*TILE_SIZE + offsetY, 0).to2D();
                for (int spriteIdx : tile.sprites) {
                    if (spriteIdx) {
                        auto sprite = &terrain->sprites[spriteIdx];
                        loadRenderable(sprite);
                        SDL_Rect destRect {(int)coords.x, (int)coords.y, 2*TILE_SIZE, 2*TILE_SIZE};
                        SDL_RenderCopyEx(
                                renderer,
                                sprite->texture,
                                &sprite->srcRect,
                                &destRect,
                                0,
                                nullptr,
                                SDL_FLIP_NONE);
                    }
                }
            }
        }
    }
}

void RenderSystem::loadRenderable(Renderable *renderable) {
    if (renderable->texture == nullptr) {
        SDL_Surface *surface = SDL_LoadBMP(renderable->spriteSheet.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        delete surface;
        renderable->texture = texture;
    }
}

void RenderSystem::poolEntity(Entity &entity, std::array<std::vector<Renderable*>, MAX_ENTITY_LAYERS> *pool,
                              const int g
                              ) {
    if (entity.hasComponent<Renderable>()) {
        auto renderComponent = entity.getComponent<Renderable>();
        auto screenPos = Vector3D();
        calcAbsolute(&entity, screenPos);
        if (screenPos.distanceTo(Vector3D(0,0,0)) < 1000) {
            pool->operator[](g).push_back(renderComponent);
        }
    }
    for (int i = 0; i < MAX_ENTITY_LAYERS; i++) {
        auto const group = entity.getGroup(i);
        std::for_each(group->begin(), group->end(),[pool, i](auto child) -> void {
            poolEntity(*child, pool, i);
        });
    }
}

[[noreturn]] void RenderSystem::poolingThread(Entity *_root) {
    for (;;) {
        auto end = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
        auto *newRenderPool = new std::array<std::vector<Renderable*>, MAX_ENTITY_LAYERS>;
        poolEntity(*_root, newRenderPool, 0);
        poolMutex.lock();
        delete renderPool;
        renderPool = newRenderPool;
        poolMutex.unlock();
        std::this_thread::sleep_until(end);
    }
}

RenderSystem::RenderSystem(Entity *_root) : System(_root) {
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    #if __APPLE__
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal");
    #endif
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("test", 0, 0, 1500, 1000, 0/*SDL_WINDOW_FULLSCREEN*/);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 52, 32, 43, 255);
    SDL_RenderSetScale(renderer, 2, 2);

    std::thread pooling([this]() -> void {
        poolingThread(root);
    });
    pooling.detach();
}
