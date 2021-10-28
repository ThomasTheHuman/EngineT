#pragma once
class Entity;

/// base class for components of entities
class Component
{
public:
	/// pointer to entity that possesses this instance of component
	Entity* entity = nullptr;
	/// virtual function that updates logic every frame
	virtual void update() {}
	/// virtual function that renders to screen
	virtual void render() {}
	virtual ~Component() = default;
};