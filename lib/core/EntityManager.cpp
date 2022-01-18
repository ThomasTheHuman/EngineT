#include "EntityManager.h"

void EntityManager::update()
{
    for (int i = 0; i < 16; i++) {
        for (auto& entity : getGroup(i)) entity->update();
    }
}

void EntityManager::render()
{
    for (int i = 0; i < 16; i++) {
        for (auto& entity : getGroup(i)) entity->render();
    }
}

void EntityManager::addToGroup(Entity* entity, std::size_t group)
{
	groupedEntities[group].emplace_back(entity);
}

std::vector<Entity*>& EntityManager::getGroup(std::size_t group)
{
	return groupedEntities[group];
}

Entity& EntityManager::addEntity()
{
	auto* entity = new Entity(*this, entities.size());
	std::unique_ptr<Entity> uPtr{entity};
	entities.emplace_back(std::move(uPtr));
	return *entity;
}

Entity& EntityManager::getEntity(int i) {
    return *entities[i].get();
}
