#include "EntityManager.h"

void EntityManager::update()
{
	for (auto& entity : entities) entity->update();
}

void EntityManager::render()
{
	for (auto& entity : entities) entity->render();
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
	auto* entity = new Entity(*this);
	std::unique_ptr<Entity> uPtr{entity};
	entities.emplace_back(std::move(uPtr));
	return *entity;
}
