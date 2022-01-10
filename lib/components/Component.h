#pragma once
class Entity;

class Component
{
public:
	Entity* entity = nullptr;
	virtual void update() {}
	virtual void render() {}
	virtual ~Component() = default;
};