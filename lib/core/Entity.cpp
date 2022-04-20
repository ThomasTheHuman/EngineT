#include "Entity.h"

Entity::Entity(): parent(this), root(true) {}

Entity::Entity(Entity& parent): parent(&parent), root(false) {}

std::vector<Entity*>* Entity::getGroup(std::size_t group)
{
    return &groupedEntities[group];
}

Entity* Entity::addEntity(std::size_t group)
{
    auto* entity = new Entity(*this);
    groupedEntities[group].emplace_back(entity);
    return entity;
}
