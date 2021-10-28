#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

///component that adds constant force to entity
class ForceComponent final : public Component
{
private:
	///amount of game frames since speed of entity was last increased
	int frameDelay = 0;
public:
	///vector of applied force
	Vector2D force;

	ForceComponent();
	ForceComponent(Vector2D& force);
	~ForceComponent() = default;

	///sets new force vector
	void setForce(Vector2D& force);
	///resets frameDelay to 1
	void reset();
	void update() override;
};