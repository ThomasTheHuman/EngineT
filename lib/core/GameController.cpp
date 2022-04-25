#include "GameController.h"
#include "../components/Transform.h"
#include "../systems/RenderSystem.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/PlayerSystem.h"
#include <algorithm>

[[noreturn]] GameController::GameController() {
    auto root = new Entity();
    root->addComponent<Transform>();
    auto terrain = root->addComponent<Terrain>();
    terrain->sprites[1].spriteSheet = "isometric.bmp";
    terrain->sprites[1].srcRect = {0, 64, 64, 64};
    terrain->sprites[2].spriteSheet = "isometric.bmp";
    terrain->sprites[2].srcRect = {64, 64, 64, 64};

    for (auto & chunkRow : terrain->chunks) {
        for (auto & chunk : chunkRow) {
            for (auto & tileRow : chunk.tiles) {
                for (auto & tile : tileRow) {
                    tile.sprites[0] = (rand()%2) + 1;
                    tile.sprites[1] = 0;
                    tile.sprites[2] = 0;
                }
            }
        }
    }

    auto entity = root->addEntity(0);
    entity->addComponent<Transform>();
    auto renderable = entity->addComponent<Renderable>();
    renderable->srcRect = {0, 64, 64, 64};
    renderable->spriteSheet = "isometric.bmp";


    systems = std::vector<System*>();
    systems.push_back(new PlayerSystem(root));
    systems.push_back(new PhysicsSystem(root));
    systems.push_back(new RenderSystem(root));
    for (;;) {
        std::for_each(systems.begin(), systems.end(), [](auto system) -> void {
            system->update();
        });
    }
}

GameController::~GameController()
{
	SDL_Quit();
}






