#include "GameController.h"
#include "../components/Transform.h"
#include "../systems/RenderSystem.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/PlayerSystem.h"
#include <algorithm>

[[noreturn]] GameController::GameController() {
    auto root = new Entity();
    root->addComponent<Transform>();

    for (int i = 0; i < 100; i++) {
        for (int j = 99; j >= 0; j--) {
            auto test = root->addEntity(0);
            auto transform = test->addComponent<Transform>();
            transform->position += Vector3D(i * 32, j * 32, 0);
            auto renderable = test->addComponent<Renderable>();
            renderable->render = true;
            renderable->srcRect = {(rand() % 2) * 64, 64, 64, 64};
            renderable->spriteSheet = "isometric.bmp";
        }
    }

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






