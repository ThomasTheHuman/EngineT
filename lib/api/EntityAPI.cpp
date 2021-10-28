#include "EntityAPI.h"
#include "../core/GameController.h"

int createEntity() {
    return GameController::entityManager.addEntity().getIndex();
}

void addEntityToGroup(int entityId, int groupId) {
    GameController::entityManager.getEntity(entityId).addGroup(groupId);
}