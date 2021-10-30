#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

/// component that stores information about position and velocity of entity
class TransformComponent final : public Component
{
private:
    TransformComponent() = default;

    Vector2D seamlessOffset;
public:
	/// vector of position of entity
	Vector2D position;
	/// vector of velocity of entity
	Vector2D velocity;

	TransformComponent(Vector2D& pos, Vector2D& offset);

	void update() override;
};