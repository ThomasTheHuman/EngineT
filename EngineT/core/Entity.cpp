#include "EntityManager.h"

Entity::Entity(EntityManager& manager): manager(manager)
{
}

void Entity::update()
{
	for (auto& component : components) component->update();
}

void Entity::render()
{
	for (auto& component : components) component->render();
}

void Entity::addGroup(std::size_t group)
{
	manager.addToGroup(this, group);
}
