#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

class TransformComponent final : public Component
{
private:
    TransformComponent() = default;

    Vector2D seamlessOffset;
public:
	Vector2D position;
	Vector2D velocity;

	TransformComponent(Vector2D& pos, Vector2D& offset);

	void update() override;
};