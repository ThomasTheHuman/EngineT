#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "CameraController.h"
#include "../components/Component.h"

class EntityManager;

/// generates new id for component
inline std::size_t getNewComponentTypeID()
{
	static std::size_t lastID = 0u;
	return lastID++;
}

/// gets id of component type (or generates new)
template <typename T>
std::size_t getComponentTypeID() noexcept
{
	static std::size_t typeID = getNewComponentTypeID();
	return typeID;
}

/// class representing game object
class Entity
{
    int i;
	/// manager possesing this instance of entity
	EntityManager& manager;
	/// vector of smart pointers to components possessed by this instance of entity
	std::vector<std::unique_ptr<Component>> components;
	/// array of pointers to components, index in array corresponds to id generated for component, speeds up calling getComponent()
	std::array<Component*, 16> componentArray{};
	/// bitset that holds data of which components entity has, speeds up calling hasComponent()
	std::bitset<16> componentBitset;

public:
	explicit Entity(EntityManager& manager, int i);
	/// calls update() of each component possessed by entity
	void update();
	/// calls render() of each component possessed by entity
	void render();
	/// adds this instance of entity to group @param group id of group to which add entity
	void addGroup(std::size_t group);
	/// checks if entity has component @tparam T type of component to check
	template <typename T> bool hasComponent() const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

	/// adds new component to entity
	/// @tparam T type of component to add
	/// @param args component constructor parameters
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... args)
	{
		T* component(new T(std::forward<TArgs>(args)...));
		component->entity = this;
		std::unique_ptr<Component>uPtr{ component };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = component;
		componentBitset[getComponentTypeID<T>()] = true;

		return *component;
	}

	/// gets component
	/// @tparam T type of component to get
	/// @return component
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	int getIndex() const {
	    return i;
	}
};