#include "PhysicsSystem.h"
#include "../components/Transform.h"
#include <thread>
#include <chrono>
#include <algorithm>

void PhysicsSystem::updateEntity(Entity &entity, long long deltaTime) {
    if (deltaTime == 0) return;
    if (entity.hasComponent<Transform>()) {
        float mult = (float)deltaTime / 1000000000.f;
        auto transform = entity.getComponent<Transform>();
        transform->velocity += (transform->acceleration * mult);
        transform->position += (transform->velocity * mult);
        transform->angularVelocity.store(transform->angularVelocity + (transform->angularAcceleration * mult));
        transform->rotation.store(transform->rotation + (transform->angularVelocity * mult));
        if (transform->rotation >= 360.f) transform->rotation.store(transform->rotation - 360.f);
        for (int i = 0; i < MAX_ENTITY_LAYERS; i++) {
            auto group = entity.getGroup(i);
            std::for_each(group->begin(), group->end(), [deltaTime](auto child) -> void {
                updateEntity(*child, deltaTime);
            });
        }
    }
}

void PhysicsSystem::physicsThread(Entity *_root) {
    long long deltaTime = 0; // nanoseconds
    for (;;) {
        auto start = std::chrono::steady_clock::now();
        updateEntity(*_root, deltaTime);
        deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::steady_clock::now() - start
                ).count();
    }
}

PhysicsSystem::PhysicsSystem(Entity *_root) : System(_root) {
    std::thread physics([_root]() -> void {
        physicsThread(_root);
    });
    physics.detach();
}
