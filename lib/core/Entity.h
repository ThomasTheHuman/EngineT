#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "../components/Component.h"


inline std::size_t getNewComponentTypeID()
{
	static std::size_t lastID = 0u;
	return lastID++;
}

template <typename T>
std::size_t getComponentTypeID() noexcept
{
	static std::size_t typeID = getNewComponentTypeID();
	return typeID;
}

class Entity
{
	std::array<Component*, 16> componentArray{};
	std::bitset<16> componentBitset;
    std::array<std::vector<Entity*>, 16> groupedEntities;

public:
    const Entity *parent;
    const bool root;

    Entity();
    Entity(Entity& parent);
	template <typename T> [[nodiscard]] bool hasComponent() const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T* addComponent(TArgs&&... args)
	{
		T* component(new T(std::forward<TArgs>(args)...));
		component->entity = this;
        auto id = getComponentTypeID<T>();
		componentArray[id] = component;
		componentBitset[id] = true;

		return component;
	}

	template<typename T> T* getComponent() const
	{
		return (T*)componentArray[getComponentTypeID<T>()];
	}

    std::vector<Entity*>* getGroup(std::size_t group);

    Entity* addEntity(std::size_t group);
};