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
    int i;
	EntityManager& manager;
	std::vector<std::unique_ptr<Component>> components;
	std::array<Component*, 16> componentArray{};
	std::bitset<16> componentBitset;

public:
	explicit Entity(EntityManager& manager, int i);
	void update();
	void render();
	void addGroup(std::size_t group);
	template <typename T> bool hasComponent() const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

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

	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	int getIndex() const {
	    return i;
	}
};