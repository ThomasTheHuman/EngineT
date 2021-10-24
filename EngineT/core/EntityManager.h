#pragma once
#include "Entity.h"

/// class that manages game objects (entities)
class EntityManager
{
	/// vector of smart pointers to every entity possessed by this instance of EntityManager
	std::vector<std::unique_ptr<Entity>> entities;
	/// array of vectors of pointers to grouped entities, index of array corresponds to group id
	std::array<std::vector<Entity*>, 16> groupedEntities;
public:
	/// updates logic of each entity
	void update();
	/// renders each entity
	void render();
	/// adds entity to group
	/// @param entity pointer to entity to be added to group
	/// @param group id of group to which add entity
	void addToGroup(Entity* entity, std::size_t group);
	/// gets group of entities
	/// @param group id of group to return
	/// @return group of entities as vector of pointers to them
	std::vector<Entity*>& getGroup(std::size_t group);
	/// creates new entity possessed by this instance of EntityManager
	/// @return new entity
	Entity& addEntity();
};