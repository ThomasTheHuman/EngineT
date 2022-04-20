#ifndef ENGINEJ_PHYSICSSYSTEM_H
#define ENGINEJ_PHYSICSSYSTEM_H


#include "System.h"
#include "../core/Entity.h"

class PhysicsSystem final : public System {
private:
    [[noreturn]] static void physicsThread(Entity *_root);
    static void updateEntity(Entity& entity, long long deltaTime);
public:
    explicit PhysicsSystem(Entity *_root);
    void update() override {};
    ~PhysicsSystem() override = default;
};


#endif //ENGINEJ_PHYSICSSYSTEM_H
