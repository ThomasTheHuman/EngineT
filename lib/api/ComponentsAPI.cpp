#include "ComponentsAPI.h"
#include "../core/GameController.h"

void addAIComponent(int entityId, int speed, bool enemy) {
    GameController::entityManager.getEntity(entityId).addComponent<AIComponent>(speed, enemy);
}

void addAnimationComponent(int entityId) {
    GameController::entityManager.getEntity(entityId).addComponent<AnimationComponent>();
}

void addAnimation(int entityId, int id, int startX, int startY, int frames) {
    GameController::entityManager
    .getEntity(entityId)
    .getComponent<AnimationComponent>()
    .addAnimation(id, *new Vector2D(startX, startY), frames);
}

void addAttackComponent(int entityId, int frames, int damageFrame, int damage) {
    GameController::entityManager.getEntity(entityId).addComponent<AttackComponent>(frames, damageFrame, damage);
}

void addCollisionComponent(int entityId) {
    GameController::entityManager.getEntity(entityId).addComponent<CollisionComponent>();
}

void addForceComponent(int entityId, float x, float y) {
    GameController::entityManager.getEntity(entityId).addComponent<ForceComponent>(*new Vector2D(x, y));
}

void addHealthComponent(int entityId, int health, int maxHealth, bool isPlayer) {
    GameController::entityManager.getEntity(entityId).addComponent<HealthComponent>(health, maxHealth, isPlayer);
}

void addPlayerComponent(int entityId, int speed) {
    GameController::entityManager.getEntity(entityId).addComponent<PlayerComponent>(speed);
}

void addSpriteComponent(int entityId, const char* id, const char* path, int w, int h, int x, int y, float scale) {
    GameController::entityManager.getEntity(entityId).addComponent<SpriteComponent>(id, path, *new Vector2D(w, h), *new Vector2D(x, y), scale);
}

void addTransformComponent(int entityId, int x, int y) {
    GameController::entityManager.getEntity(entityId).addComponent<TransformComponent>(*new Vector2D(x, y));
}

