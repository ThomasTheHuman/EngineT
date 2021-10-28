#pragma once
#ifdef __cplusplus
extern "C" {
#endif

    void addAIComponent(int entityId, int speed, bool enemy);

    void addAnimationComponent(int entityId);
    void addAnimation(int entityId, int id, int startX, int startY, int frames);

    void addAttackComponent(int entityId, int frames, int damageFrame, int damage);

    void addCollisionComponent(int entityId);

    void addForceComponent(int entityId, float x, float y);

    void addHealthComponent(int entityId, int health, int maxHealth, bool isPlayer);

    void addPlayerComponent(int entityId, int speed);

    void addSpriteComponent(int entityId, const char* id, const char* path, int w, int h, int x, int y, float scale);

    void addTransformComponent(int entityId, int x, int y);

#ifdef __cplusplus
}
#endif