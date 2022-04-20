#include "RenderSystem.h"
#include "../components/Transform.h"
#include <algorithm>
#include <thread>
#include <chrono>

std::mutex RenderSystem::poolMutex = std::mutex();
std::array<std::vector<Renderable*>, 16> *RenderSystem::renderPool;

void RenderSystem::calcAbsolute(const Entity *entity, Vector3D &absolutePosition) {
    absolutePosition += entity->getComponent<Transform>()->position;
    if (!entity->root) {
        calcAbsolute(entity->parent, absolutePosition);
    }
}

void RenderSystem::update() {
    SDL_SetRenderDrawColor(renderer, 140, 140, 140, 255);
    SDL_RenderClear(renderer);
    if (renderPool != nullptr) {
        poolMutex.lock();
        std::for_each(renderPool->begin(), renderPool->end(), [this](std::vector<Renderable*> group) -> void {
            // TODO sort by position
            std::for_each(group.begin(), group.end(), [this](Renderable *renderable) -> void {
                auto entity = renderable->entity;
                auto absolute = Vector3D();
                calcAbsolute(entity, absolute);
                auto absolute2D = absolute.to2D();

                if (renderable->texture == nullptr) {
                    SDL_Surface *surface = SDL_LoadBMP(renderable->spriteSheet.c_str());
                    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
                    delete surface;
                    renderable->texture = texture;
                }
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
        poolMutex.unlock();
    }
    SDL_RenderPresent(renderer);
}

void RenderSystem::poolEntity(Entity &entity, std::array<std::vector<Renderable*>, 16> *pool, int g) {
    if (entity.hasComponent<Renderable>()) {
        auto renderComponent = entity.getComponent<Renderable>();
        if (renderComponent->render) {
            pool->operator[](g).push_back(renderComponent);
        }
    }
    for (int i = 0; i < 16; i++) {
        auto const group = entity.getGroup(i);
        std::for_each(group->begin(), group->end(),[pool, i](auto child) -> void {
            poolEntity(*child, pool, i);
        });
    }
}

[[noreturn]] void RenderSystem::poolingThread(Entity *_root) {
    for (;;) {
        auto end = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
        auto *newRenderPool = new std::array<std::vector<Renderable*>, 16>;
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
    window = SDL_CreateWindow("test", 0, 0, 1000, 1000, 0/*SDL_WINDOW_FULLSCREEN*/);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 52, 32, 43, 255);
    SDL_RenderSetScale(renderer, 2, 2);

    std::thread pooling([this]() -> void {
        poolingThread(root);
    });
    pooling.detach();
}
