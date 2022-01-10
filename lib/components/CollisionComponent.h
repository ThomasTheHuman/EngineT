#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

// adds collisions with entities of group 1
class CollisionComponent final : public Component
{
public:
	void update() override;
};
