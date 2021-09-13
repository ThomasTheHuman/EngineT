#pragma once
#include "Component.h"
#include "Vector2D.h"

/// component that stores information about position and velocity of entity
class TransformComponent final : public Component
{
public:
	/// vector of position of entity
	Vector2D position;
	/// vector of velocity of entity
	Vector2D velocity;

	TransformComponent();

	TransformComponent(Vector2D& pos);
	/// returns absolute (relative to map and not to screen) position, unused functionality
	Vector2D getAbsolute() const;
	/// sets position relative to map and not to screen, unused functionality
	void setAbsolute(Vector2D pos);

	void update() override;
};