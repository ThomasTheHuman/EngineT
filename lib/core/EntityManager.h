#pragma once
#include "Entity.h"

class EntityManager
{
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, 16> groupedEntities;
public:
	void update();
	void render();

	void addToGroup(Entity* entity, std::size_t group);

	std::vector<Entity*>& getGroup(std::size_t group);

	Entity& addEntity();
	Entity& getEntity(int i);
};